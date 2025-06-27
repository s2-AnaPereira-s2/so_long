/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:03:38 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/06/27 19:56:38 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void game_win(t_game *game)
{
	game->game_win = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->p_x, game->p_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->exit_x, game->exit_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img[7], 300, 300);
}

int	move_check(t_game *game)
{
	int map_x;
	int map_y;

	game->game_win = 0;
	map_x = game->np_x / game->tile_w;
	map_y = game->np_y / game->tile_h;

	if (game->collectables == 0 && game->map[map_y][map_x] == 'E')
		return(game_win(game), 1);
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == 'E')
		return (1);
	else if (game->map[map_y][map_x] == 'C')
		return (game->map[map_y][map_x] = '0', game->collectables -= 1, 0);
	return (0);
}

void	get_score(t_game *game)
{
	char	*score_str;

	score_str = ft_itoa(game->movements);
	mlx_put_image_to_window(game->mlx, game->win, game->img[6], 100, game->map_height);
	mlx_string_put(game->mlx, game->win, 550, game->map_height + 70, 0xFFFFFF, score_str);
	ft_printf("Movements = %d\n", game->movements);
	free(score_str);
}

void move_player(t_game *game, int	keycode)
{
	if (keycode == KEY_RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->p_x, game->p_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->img[4], game->np_x, game->np_y);
	}
	else if (keycode == KEY_LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->p_x, game->p_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->img[5], game->np_x, game->np_y);
	}
	else if (keycode == KEY_UP)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->p_x, game->p_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->img[3], game->np_x, game->np_y);
	}
	else if (keycode == KEY_DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->p_x, game->p_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->img[2], game->np_x, game->np_y);
	}
	game->movements += 1;
	game->p_x = game->np_x;
	game->p_y = game->np_y;
}