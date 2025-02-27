/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:48:16 by marioga2          #+#    #+#             */
/*   Updated: 2024/12/19 17:23:51 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c);
static char		*ft_copy_word(const char *s, size_t start, size_t end);
static void		ft_free_split(char **result, size_t k);
static int		ft_fill_words(const char *s, char c, char **result, size_t *k);

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copy_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc((end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill_words(const char *s, char c, char **result, size_t *k)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			result[*k] = ft_copy_word(s, j, i);
			if (!result[*k])
				return (0);
			(*k)++;
		}
	}
	return (1);
}

static void	ft_free_split(char **result, size_t k)
{
	while (k > 0)
		free(result[--k]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	k;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = malloc((word_count + 1) * (unsigned long)8);
	if (!result)
		return (NULL);
	k = 0;
	if (!ft_fill_words(s, c, result, &k))
	{
		ft_free_split(result, k);
		return (NULL);
	}
	result[k] = NULL;
	return (result);
}
