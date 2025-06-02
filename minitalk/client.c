/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:35:07 by marioga2          #+#    #+#             */
/*   Updated: 2025/06/01 16:35:07 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",
			STDOUT_FILENO);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr_fd("\e[92msending length = [", STDOUT_FILENO);
		ft_putnbr_fd(ft_strlen(str), STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		send_int(server_pid, ft_strlen(str));
		ft_putstr_fd("\e[92msending message\n\e[0m", STDOUT_FILENO);
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		ft_putstr_fd("\e[92msending null string terminator\n\e[0m", STDOUT_FILENO);
		send_char(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr_fd("\e[31m## error - incorrect syntax ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd(
			"\e[92m./client <the server PID> <the string to send>\n\e[0m",
			STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[31m## error - PID is invalid ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_putstr_fd("\e[92mclient [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	client_send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}