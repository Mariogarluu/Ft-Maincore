# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 12:27:41 by marioga2          #+#    #+#              #
#    Updated: 2024/12/19 15:43:58 by marioga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_is.c ft_itoa.c ft_malloc.c ft_mem.c ft_mem_2.c \
      ft_put.c ft_split.c ft_str.c ft_str_2.c ft_str_3.c ft_str_4.c ft_miss.c
BONUS_SRCS = ft_lst.c ft_lst_2.c

OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
ALL_OBJS = $(OBJ)

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) $(NAME) $(ALL_OBJS)

bonus: $(OBJ) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	$(eval ALL_OBJS += $(BONUS_OBJS))

clean:
	$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
