/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:02:03 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/02 16:46:27 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void    *mlx_destroy_display;
    char    **map;
	char	**map_cpy;
	void	**img;
    int     img_width;
    int     img_height;
	int		win_width;
	int		win_height;
	int		map_height;
	int		tile_w;
	int		tile_h;
	int		line_len;
    int     fd;
    int		p_x;
	int		p_y;
	int		np_x;
	int		np_y;
	int		game_win;
	int		exit_x;
	int		exit_y;
    int     collectables;
	int		movements;
	int		p;
	int		e;
}	t_game;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_printf(const char *para, ...);
int	ft_putchar(char c);
int	ft_putunbr(unsigned int n);
char	*ft_itoa(int n);
int	get_image(t_game *game);
int	get_map(t_game *game);
void	put_image_map(int y, int x, t_game *game);
void	draw_map(t_game *game);
void	get_score(t_game *game);
void move_player(t_game *game, int	keycode);
int	move_check(t_game *game);
int	map_check(t_game *game);
void	*ft_calloc(size_t nmemb, size_t size);
void	map_copy(t_game *game);
void	get_cep(t_game *game);
void	get_pos(t_game *game);
int	get_helpers(t_game *game);

#endif