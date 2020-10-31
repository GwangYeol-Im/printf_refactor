# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gim <gim@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 14:26:20 by gim               #+#    #+#              #
#    Updated: 2020/10/31 10:15:17 by gim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

LIBFT = libft.a

SRCS = ft_printf.c \
		print_char.c \
		print_num.c \
		print_str.c \
		util.c \
		util2.c \

OBJS = $(SRCS:c=o)

%.o: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME): $(LIBFT) $(OBJS)
		mkdir libft_o && cd libft_o && ar -x ../libft/libft.a && cd ..
		$(AR) $(ARFLAGS) $@ libft_o/*.o $(OBJS)
		rm -rf libft_o

$(LIBFT):
		make -C libft/

test:
		gcc test.c -L. -lftprintf

all: $(NAME)

clean:
		make clean -C libft/
		$(RM) $(OBJS) $(OBJS_B)

fclean:
		make fclean -C libft/
		$(RM) $(OBJS) $(OBJS_B)
		$(RM) $(NAME) $(LIBFT)

re: fclean all