/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:20:06 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 17:52:23 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_game *game)
{
	int	move;

	game->np_x = game->p_x;
	game->np_y = game->p_y;
	if (game->game_win)
		return (close_window(game), 0);
	if (game->collectables == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[10], 
			game->exit_x, game->exit_y);
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
		move_player(game, keycode);
		get_score(game);
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		size;

	if (argc <= 1)
		return (0);
	init_game(&game);
	game.mlx = mlx_init();
	game.file_name = argv[1];
	size = get_map(&game);
	game.map_height = (size - 1) * 32;
	game.win_width = (game.line_len - 1) * 32;
	game.win_height = game.map_height + (3 * 32);
	if (window_check(&game))
		return (perror("Map bigger than screen!"), exit(0), 0);
	game.win = mlx_new_window(game.mlx, game.win_width, 
			game.win_height, "Turtle");
	get_image(&game);
	get_helpers(&game);
	if (map_check(&game))
		return (free(game.map), free(game.file_name), 0);
	draw_map(&game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
