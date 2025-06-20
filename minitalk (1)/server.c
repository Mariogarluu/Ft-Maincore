/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:35:12 by marioga2          #+#    #+#             */
/*   Updated: 2025/06/20 12:58:57 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_and_free(t_protocol *p)
{
	ft_putstr_fd("=====", STDOUT_FILENO);
	ft_putstr_fd(p->message, STDOUT_FILENO);
	ft_putstr_fd("=====\n", STDOUT_FILENO);
	free(p->message);
	p->message = NULL;
}

static void	handle_message(t_protocol *p, int *i)
{
	if (p->bits == 8 && p->flag == 1)
	{
		p->message[*i] = p->data;
		(*i)++;
		if (p->data == '\0')
		{
			print_and_free(p);
			p->flag = 0;
			*i = 0;
		}
		p->bits = 0;
	}
}

static void	handle_length(t_protocol *p)
{
	if (p->bits == sizeof(int) * 8 && p->flag == 0)
	{
		p->flag = 1;
		p->message = ft_calloc(p->data + 1, sizeof(char));
		if (!p->message)
		{
			ft_putstr_fd("Error: calloc failed\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		p->bits = 0;
	}
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static t_protocol	p;
	static int			i;

	(void)context;
	if (p.bits == 0)
		p.data = 0;
	if (sig == SIGUSR2)
	{
		if (p.flag == 0)
			p.data |= 1 << ((sizeof(int) * 8 - 1) - p.bits);
		else
			p.data |= 1 << ((sizeof(char) * 8 - 1) - p.bits);
	}
	p.bits++;
	handle_length(&p);
	handle_message(&p, &i);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&sa);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
