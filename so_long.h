/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:02:03 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/06/25 19:08:01 by ana-pdos         ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
    void    *wall_img;
	void    *collectable_img;
	void    *grass_img;
	void    *player_front_img;
	void    *player_right_img;
	void    *player_left_img;
	void    *player_back_img;
	void    *exit_img;
	void    *open_exit_img;
	void    *win2_img;
	void    *score_back_img;
    char    **map;
    int     img_width;
    int     img_height;
	int		win_width;
	int		win_height;
	int		map_height;
	int		tile_w;
	int		tile_h;
	int		line_len;
    void    *mlx_destroy_display;
    int     fd;
    int		player_x;
	int		player_y;
	int		new_player_x;
	int		new_player_y;
	int		game_win;
	int		exit_x;
	int		exit_y;
    int     collectable_score;
	int		movements;
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

#endif