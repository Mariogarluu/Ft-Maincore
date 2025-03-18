/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:12:24 by marioga2          #+#    #+#             */
/*   Updated: 2025/02/10 12:46:21 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, size_t *counter);
void	ft_putstr(const char *str, size_t *counter);
void	ft_putptr(void *ptr, size_t *counter);
void	ft_putnbr(int n, size_t *counter);
void	ft_putuint(unsigned int n, size_t *counter);
void	ft_puthex(unsigned long long num, size_t *counter, const char *base);
char	*ft_aux(unsigned long long n, char *base);

#endif