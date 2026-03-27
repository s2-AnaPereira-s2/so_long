# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 21:15:09 by ana-pdos          #+#    #+#              #
#    Updated: 2025/08/13 21:52:13 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I. -I$(GNL_DIR) -I$(PRINTF_DIR)
GNL_DIR = get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_DIR = ft_printf
PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_hex_convert_lower.c \
	    $(PRINTF_DIR)/ft_hex_convert_upper.c $(PRINTF_DIR)/ft_hex_convert_p.c \
	    $(PRINTF_DIR)/ft_putnbr_pf.c $(PRINTF_DIR)/ft_putstr_pf.c $(PRINTF_DIR)/ft_putchar_pf.c \
		$(PRINTF_DIR)/ft_putunbr_pf.c
CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	 ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	 ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strrchr.c \
	 ft_strdup.c ft_strlen.c ft_strlcpy.c ft_strjoin.c ft_strlcat.c \
	 ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_strchr.c \
	 ft_tolower.c ft_toupper.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c\
	 ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	 $(GNL_SRCS) $(PRINTF_SRCS)

OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re 


all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
