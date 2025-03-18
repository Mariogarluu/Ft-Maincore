/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:59:14 by marioga2          #+#    #+#             */
/*   Updated: 2024/12/19 17:22:19 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substr_len(char const *s, unsigned int start, size_t len);
static size_t	ft_strjoin_len(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	substr_len;

	if (!s)
		return (NULL);
	substr_len = ft_substr_len(s, start, len);
	substr = (char *)malloc(substr_len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

static size_t	ft_substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (0);
	if (len > s_len - start)
		return (s_len - start);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strjoin_len(s1, s2);
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

static size_t	ft_strjoin_len(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (len1 + len2);
}
