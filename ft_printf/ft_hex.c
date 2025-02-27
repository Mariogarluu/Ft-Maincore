/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:29:38 by marioga2          #+#    #+#             */
/*   Updated: 2025/02/10 12:37:06 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long num, size_t *counter, const char *base)
{
	char	*str;

	str = ft_aux(num, (char *)base);
	ft_putstr(str, counter);
	free(str);
}
