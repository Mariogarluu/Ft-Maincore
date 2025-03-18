/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:53:17 by marioga2          #+#    #+#             */
/*   Updated: 2025/01/10 13:11:12 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
