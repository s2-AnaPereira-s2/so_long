/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:57:24 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/02 16:57:18 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(t_game *game)
{
	int y;

	y = 0;
	game->map_cpy = ft_calloc((game->map_height / 32) + 1, sizeof(char *));
	if (!game->map_cpy)
		return;
	while (game->map[y])
	{
		game->map_cpy[y] = ft_strdup(game->map[y]);
		if (!game->map_cpy[y])
			return;
		y++;
	}
}

void	get_cep(t_game *game)
{
	int	y;
	int	x;
	
	game->p = 0;
	game->e = 0;
	game->collectables = 0;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
				game->p += 1;
			else if (game->map[y][x] == 'E')
				game->e += 1;
			else if (game->map[y][x] == 'C')
				game->collectables += 1;
			x++;
		}
		y++;
	}
}

void	get_pos(t_game *game)
{
	int	y;
	int	x;
	
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = game->img_width * x;
				game->p_y = game->img_height * y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_x = game->img_width * x;
				game->exit_y = game->img_height * y;
			}
			x++;
		}
		y++;
	}
}

int	get_helpers(t_game *game)
{
	map_copy(game);
	get_pos(game);
	get_cep(game);
	return (0);
}
