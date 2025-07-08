/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:03:38 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 18:59:15 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_p(t_game *game)
{
	int	p;

	p = (game->win_width - 96) / 2;
	return (p);
}

void	game_win(t_game *game)
{
	game->game_win = 1;
	put_img_window(game, game->img[1], game->p_x, game->p_y);
	put_img_window(game, game->img[1], game->exit_x, game->exit_y);
	put_img_window(game, game->img[7], start_p(game), 32);
	ft_printf("%s\n", "You win!!!");
}

int	move_check(t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = game->np_x / game->img_width;
	map_y = game->np_y / game->img_height;
	if (game->collectables == 0 && game->map[map_y][map_x] == 'E')
		return (game_win(game), 1);
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
	put_img_window(game, game->img[6], start_p(game), game->map_height);
	mlx_string_put(game->mlx, game->win, game->win_width / 2, 
		game->map_height + 60, 0xFFFFFF, score_str);
	ft_printf ("Movements = %d\n", game->movements);
	free (score_str);
}

int	move_player(t_game *game, int keycode)
{
	if (keycode == KEY_ESC)
		return (close_window(game), 0);
	if (keycode == KEY_RIGHT)
	{
		put_img_window(game, game->img[1], game->p_x, game->p_y); 
		put_img_window(game, game->img[4], game->np_x, game->np_y);
	}
	else if (keycode == KEY_LEFT)
	{
		put_img_window(game, game->img[1], game->p_x, game->p_y); 
		put_img_window(game, game->img[5], game->np_x, game->np_y);
	}
	else if (keycode == KEY_UP)
	{
		put_img_window(game, game->img[1], game->p_x, game->p_y); 
		put_img_window(game, game->img[3], game->np_x, game->np_y);
	}
	else if (keycode == KEY_DOWN)
	{
		put_img_window(game, game->img[1], game->p_x, game->p_y); 
		put_img_window(game, game->img[2], game->np_x, game->np_y);
	}
	else
		return (0);
	return (game->movements++, game->p_x = game->np_x, game->p_y = game->np_y);
}
