/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:32:36 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/02 17:45:56 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	get_map(t_game *game)
{
	char    *line;
	int		size;

	game->fd = open("maps/map_abc.ber", O_RDONLY);
	line = get_next_line(game->fd);
	game->line_len = ft_strlen(line);
	size = 1;
	while (line && size++)
		line = get_next_line(game->fd);
	close(game->fd);
	game->map = ft_calloc(sizeof(char *), size);
	if (!game->map)
		return (0);
	game->fd = open("maps/map_abc.ber", O_RDONLY);
    line = get_next_line(game->fd);
	game->map[0] = line;
	size = 1;
	while (line)
	{
		line = get_next_line(game->fd);
		game->map[size] = line;
		size++;
	}
	return (close(game->fd), size);
}

void	*file_to_img(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path, &game->img_width, &game->img_height));
}

int	get_image(t_game *game)
{
	int i;
	int size;

	size = 11;
	game->img = malloc(sizeof(void *) * (size + 1));
	if (!game->img)
		return (perror("Failed to allocate image array"), 1);
	game->img[0] = file_to_img(game, "textures/wall.xpm");
	game->img[1] = file_to_img(game, "textures/grass.xpm");
	game->img[2] = file_to_img(game, "textures/player_front.xpm");
	game->img[3] = file_to_img(game, "textures/player_back.xpm");
	game->img[4] = file_to_img(game, "textures/player_right.xpm");
	game->img[5] = file_to_img(game, "textures/player_left.xpm");
	game->img[6] = file_to_img(game, "textures/moves_score.xpm");
	game->img[7] = file_to_img(game, "textures/win.xpm");
	game->img[8] = file_to_img(game, "textures/collectable.xpm");
	game->img[9] = file_to_img(game, "textures/door.xpm");
	game->img[10] = file_to_img(game, "textures/open_door.xpm");
	while (size--)
		if(!game->img[size - 1])
			return (perror("Error to load image"), mlx_destroy_window(game->mlx, game->win), 1);
	return (0);
}


void	put_image_map(int y, int x, t_game *game)
{
	while (game->map[y][x] && game->map[y][x] != '\n')
    {
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->img_width * x, game->img_height * y);
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img[0], game->img_width * x, game->img_height * y);
		else if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img[8], game->img_width * x, game->img_height * y);
		else if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->img[2], game->img_width * x, game->img_height * y);
		else if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img[9], game->img_width * x, game->img_height * y);
		x++;
	}
}

void	draw_map(t_game *game)
{
	int     x;
	int		y;

	game->movements = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		put_image_map(y, x, game);
		y++;
	}
}