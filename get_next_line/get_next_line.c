/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:53:09 by marioga2          #+#    #+#             */
/*   Updated: 2025/01/20 12:53:14 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **remainder)
{
	char	*newline;
	char	*line;
	char	*new_remainder;

	newline = ft_strchr(*remainder, '\n');
	if (newline)
	{
		line = malloc(newline - *remainder + 2);
		if (!line)
			return (NULL);
		ft_strncpy(line, *remainder, newline - *remainder + 1);
		line[newline - *remainder + 1] = '\0';
		new_remainder = ft_strdup(newline + 1);
	}
	else
	{
		line = ft_strdup(*remainder);
		new_remainder = NULL;
	}
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

static int	prepare_remainder(char **remainder)
{
	if (!*remainder)
	{
		*remainder = malloc(1);
		if (!*remainder)
			return (-1);
		**remainder = '\0';
	}
	return (0);
}

static int	read_loop(int fd, char **remainder, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	while (!ft_strchr(*remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*remainder, buffer);
		if (!temp)
			return (-1);
		*remainder = temp;
	}
	return (0);
}

static int	read_and_concatenate(int fd, char **remainder)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	if (prepare_remainder(remainder) < 0)
	{
		free(buffer);
		return (-1);
	}
	if (read_loop(fd, remainder, buffer) < 0)
	{
		free(buffer);
		free(*remainder);
		*remainder = NULL;
		return (-1);
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_and_concatenate(fd, &remainder) < 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	if (remainder == NULL || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (extract_line(&remainder));
}
