/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:07:45 by marioga2          #+#    #+#             */
/*   Updated: 2025/02/10 12:38:28 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*counter) += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*counter)++;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
		(*counter)++;
	}
}

void	ft_putuint(unsigned int n, size_t *counter)
{
	if (n > 9)
	{
		ft_putuint(n / 10, counter);
		ft_putuint(n % 10, counter);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
		(*counter)++;
	}
}
