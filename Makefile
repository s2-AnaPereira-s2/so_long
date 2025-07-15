# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 14:34:13 by ana-pdos          #+#    #+#              #
#    Updated: 2025/07/14 09:45:44 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_DIR = minilibx-linux
INCLUDES = -I$(MLX_DIR)
MLX_LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lbsd
CFILES = so_long.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c so_long_utils5.c get_next_line.c ft_printf.c draw_map.c move_player.c ft_calloc.c ft_itoa.c map_check.c clean.c
OFILES = $(CFILES:.c=.o)


.PHONY: all clean fclean re 


all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OFILES) $(MLX_LIBS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
