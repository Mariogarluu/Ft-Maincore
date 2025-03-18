/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:57:50 by marioga2          #+#    #+#             */
/*   Updated: 2024/12/12 16:06:31 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(char *str, int n, int len)
{
	unsigned int	num;

	if (n < 0)
		num = -n;
	else
		num = n;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if (n < 0 && len == 0)
		{
			str[len] = '-';
			break ;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = ft_num_len(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_fill_str(result, n, len);
	return (result);
}
