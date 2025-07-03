# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 14:34:13 by ana-pdos          #+#    #+#              #
#    Updated: 2025/07/02 15:08:34 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
CFILES = so_long.c so_long_utils1.c so_long_utils2.c get_next_line.c ft_printf.c draw_map.c move_player.c ft_calloc.c helpers.c
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re 


all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
