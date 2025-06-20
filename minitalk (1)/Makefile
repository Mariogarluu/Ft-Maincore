# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 13:15:58 by marioga2          #+#    #+#              #
#    Updated: 2025/06/20 12:34:35 by marioga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

# Project names
NAME_SERVER := server
NAME_CLIENT := client

# Source files
SRCS_SERVER := server.c utils.c
SRCS_CLIENT := client.c utils.c

# Object files
OBJS_SERVER := $(SRCS_SERVER:.c=.o)
OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)

# Libft
LIBFT_PATH  := ./import
LIBFT       := $(LIBFT_PATH)/libft.a
INCLUDES    := -I. -I$(LIBFT_PATH)

# Build rules
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Libft dependency (assumes precompiled libft.a)
$(LIBFT):
	@echo "libft.a not found in import/. Please compile it manually."
#	make -C $(LIBFT_PATH)

# Clean rules
clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

# Norminette
norm:
	norminette *.c *.h

.PHONY: all clean fclean re norm