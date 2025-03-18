/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:11 by marioga2          #+#    #+#             */
/*   Updated: 2024/12/19 15:33:58 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
