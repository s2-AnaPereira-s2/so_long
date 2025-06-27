/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:20:06 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/06/27 19:12:54 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	close_window()
{
	exit(0);
	return (0);
}

int keypress(int keycode, t_game *game)
{
	int	move;
	char *move_str;
	
	game->np_x = game->p_x;
	game->np_y = game->p_y;
	if (game->game_win)
		return (0);
	if (game->collectables == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[10], game->exit_x, game->exit_y);
	if (keycode == KEY_RIGHT)
		game->np_x += 32;
	else if (keycode == KEY_LEFT)
		game->np_x -= 32;
	else if (keycode == KEY_UP)
		game->np_y -= 32;
	else if (keycode == KEY_DOWN)
		game->np_y += 32;
	move = move_check(game);
	if (move == 0)
	{
		get_score(game);
		return (move_player(game, keycode), 0);
	}
	return (0);
}


int	main(void)
{
	t_game	game;
	int		size;

	game.mlx = mlx_init();
	size = get_map(&game);
	game.map_height = (size - 1) * 32;
	game.win_width = (game.line_len - 1) * 32;
	game.win_height = game.map_height + (3 * 32);
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, "Ana Game!");
	get_image(&game);
	draw_map(&game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
    return (0);
}
