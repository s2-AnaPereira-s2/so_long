/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:57:24 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/14 18:14:50 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->img_width = 0;
	game->img_height = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->map_height = 0;
	game->tile_w = 0;
	game->tile_h = 0;
	game->line_len = 0;
	game->fd = -1;
	game->p_x = 0;
	game->p_y = 0;
	game->np_x = 0;
	game->np_y = 0;
	game->game_win = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectables = 0;
	game->movements = 0;
	game->p = 0;
	game->e = 0;
	game->map_cpy = NULL;
	game->map = NULL;
	game->img = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	*file_to_img(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path, 
			&game->img_width, &game->img_height));
}

int	check_images(t_game *game, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!game->img[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_length(t_game *game)
{
	char	*line;
	int		size;

	game->fd = open(game->file_name, O_RDONLY);
	if (game->fd < 0)
		return (perror("Wrong file"), close(game->fd), close_window(game));
	if (bad_extension(game))
		return (close(game->fd), close_window(game));
	line = get_next_line(game->fd);
	game->line_len = ft_strlen(line);
	size = 1;
	while (line && size++)
	{
		free(line);
		line = get_next_line(game->fd);
	}
	close(game->fd);
	return (size);
}

int	window_check(t_game *game)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (game->win_width > screen_width || game->win_height > screen_height)
		return (1);
	return (0);
}
