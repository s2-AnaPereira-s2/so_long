/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:42:19 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 19:00:36 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(t_game *game)
{
	int	y;

	y = 0;
	game->map_cpy = ft_calloc((game->map_height / 32) + 1, sizeof(char *));
	if (!game->map_cpy)
		return ;
	while (game->map[y])
	{
		game->map_cpy[y] = ft_strdup(game->map[y]);
		if (!game->map_cpy[y])
			return ;
		y++;
	}
}

void	get_cep(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
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
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
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

int	put_img_window(t_game *game, char *img, int x, int y)
{
	return (mlx_put_image_to_window(game->mlx, game->win, img, x, y));
}
