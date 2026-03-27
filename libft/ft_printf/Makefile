# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 16:33:37 by ana-pdos          #+#    #+#              #
#    Updated: 2025/08/13 21:51:29 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
CFILES = ft_hex_convert_lower.c ft_hex_convert_upper.c ft_hex_convert_p.c ft_printf.c ft_putnbr_pf.c ft_putstr_pf.c ft_putchar_pf.c ft_putunbr_pf.c
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re 


all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
