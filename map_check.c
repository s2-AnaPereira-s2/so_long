/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:18:15 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/14 18:09:56 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	y;
	int	x;
	int	temp;

	temp = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			x++;
			if (y == 0)
				temp = x;
		}
		if (temp != x)
			return (1);
		temp = x;
		y++;
	}
	return (0);
}

int	p_e_collectables(t_game *game)
{
	if (game->p != 1 || game->e != 1 || game->collectables == 0)
		return (1);
	return (0);
}

int	wall_surround(t_game *game)
{
	int	y;
	int	x;

	y = (game->map_height / game->img_height) - 1;
	x = (game->win_width / game->img_width) - 1;
	while (y >= 0)
	{
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
			return (1);
		y--;
	}
	y = (game->map_height / game->img_height) - 1;
	while (x >= 0)
	{
		if (game->map[0][x] != '1' || game->map[y][x] != '1')
			return (1);
		x--;
	}
	return (0);
}

int	is_path(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map_height / 32 || x >= game->line_len)
		return (0);
	if (game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'X' 
		|| game->map_cpy[y][x] == 'O')
		return (0);
	if (game->map_cpy[y][x] == 'E')
	{
		game->map_cpy[y][x] = 'O';
		return (0);
	}
	game->map_cpy[y][x] = 'X';
	is_path(game, y - 1, x);
	is_path(game, y + 1, x);
	is_path(game, y, x + 1);
	is_path(game, y, x - 1);
	return (0);
}

int	map_check(t_game *game)
{
	int	i;
	int	j;

	if (is_rectangular(game))
		return (perror("Map is not rectangular"), close_window(game));
	if (p_e_collectables(game))
		return (perror("2 players/exit or 0 collectable"), close_window(game));
	if (wall_surround(game))
		return (perror("Map not surrounded by walls"), close_window(game));
	if (is_path(game, game->p_y / 32, game->p_x / 32))
		return (perror("Player outside the map"), close_window(game));
	i = 0;
	while (game->map_cpy[i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] == 'C' || game->map_cpy[i][j] == 'E')
				return (perror("Map has no valid path"), close_window(game));
			j++;
		}
		i++;
	}
	return (0);
}
