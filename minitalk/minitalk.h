/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:35:00 by marioga2          #+#    #+#             */
/*   Updated: 2025/06/01 16:35:00 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define WAIT_US  100

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "import/libft.h"
# include "import/ft_printf.h"

void	configure_sigaction_signals(struct sigaction *sa);
void	send_int(pid_t pid, int num);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit, char flag_to_pause);

typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_protocol;

#endif
