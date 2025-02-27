/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:07:48 by marioga2          #+#    #+#             */
/*   Updated: 2025/02/10 12:49:50 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str, size_t *counter)
{
	if (!str)
	{
		write(1, "(null)", 6);
		(*counter) += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		(*counter)++;
		str++;
	}
}

void	ft_putchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putptr(void *ptr, size_t *counter)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*counter) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*counter) += 2;
	ft_puthex((unsigned long long)ptr, counter, HEX_LOW_BASE);
}
