# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 13:15:58 by marioga2          #+#    #+#              #
#    Updated: 2025/06/02 13:15:58 by marioga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client



SRC_SERVER := server.c minitalk.c
SRC_CLIENT := client.c minitalk.c

INCLUDES := -I. -Ilibft

LIBFT := ./import/libft.a
LIBFT_PATH := ./libft
PRINTF := ./impor/ft_printf.a



all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

clean:


fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)


re: fclean all

.PHONY: all clean fclean re bonus rebonus