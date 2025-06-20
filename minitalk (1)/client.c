/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:35:07 by marioga2          #+#    #+#             */
/*   Updated: 2025/06/20 13:12:47 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

static void	send_message(int pid, char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	send_int(pid, len);
	i = 0;
	while (str[i])
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error: invalid syntax\n", STDERR_FILENO);
		ft_putstr_fd("Usage: ./client <PID> <message>\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_printf("__PID: %d\n", getpid());
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
	{
		ft_putstr_fd("Error: invalid PID\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = client_handler;
	configure_sigaction_signals(&sa);
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
