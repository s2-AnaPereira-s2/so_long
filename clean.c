/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:48:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 18:54:53 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	int	i;
	int	size;

	size = 11;
	if (!game->img)
		return ;
	i = 0;
	while (i < size)
	{
		if (game->img[i])
			mlx_destroy_image(game->mlx, game->img[i]);
		i++;
	}
	free(game->img);
	game->img = NULL;
}

void	free_map_cpy(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map_cpy)
		return ;
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		game->map_cpy[i] = NULL;
		i++;
	}
	free(game->map_cpy);
	game->map_cpy = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map && game->map[i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	free_map_cpy(game);
	game->map = NULL;
}

int	close_window(t_game *game)
{
	if (game->map)
		free_map(game);
	if (game->img)
		free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_printf("\n%s\n", "...bye bye!!!");
	exit(0);
	return (0);
}
