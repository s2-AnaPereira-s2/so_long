/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:32:36 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 18:36:19 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(t_game *game)
{
	char	*line;
	int		size;

	size = get_length(game);
	if (size == 0)
		return (0);
	game->map = ft_calloc(sizeof(char *), size);
	if (!game->map)
		return (0);
	game->fd = open(game->file_name, O_RDONLY);
	if (game->fd < 0)
		return (0);
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

int	get_image(t_game *game)
{
	int	i;

	game->img = malloc(sizeof(void *) * (12));
	if (!game->img)
		return (ft_printf("Error\n"), exit(1), 1);
	i = 0;
	while (i < 11)
	{
		game->img[i] = NULL;
		i++;
	}
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
	if (check_images(game, 11))
		return (perror("Error: failed to load image\n"), 1);
	return (0);
}

void	put_image_map(int y, int x, t_game *game)
{
	while (game->map[y][x] && game->map[y][x] != '\n')
	{
		put_img_window(game, game->img[1], game->img_width * x, 
			game->img_height * y);
		if (game->map[y][x] == '1')
			put_img_window(game, game->img[0], game->img_width * x, 
				game->img_height * y);
		else if (game->map[y][x] == 'C')
			put_img_window(game, game->img[8], game->img_width * x, 
				game->img_height * y);
		else if (game->map[y][x] == 'P')
			put_img_window(game, game->img[2], game->img_width * x, 
				game->img_height * y);
		else if (game->map[y][x] == 'E')
			put_img_window(game, game->img[9], game->img_width * x, 
				game->img_height * y);
		x++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		put_image_map(y, x, game);
		y++;
	}
}
