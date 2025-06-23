#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	get_map_size(t_game *game)
{
	char    *line;
	int		size;

	game->fd = open("maps/map1.ber", O_RDONLY);
	line = get_next_line(game->fd);
	game->line_len = ft_strlen(line);
	size = 1;
	while (line)
	{
		line = get_next_line(game->fd);
		size++;
	}
	close(game->fd);
	return (size);
}

int	close_window()
{
	exit(0);
	return (0);
}


void	draw_map(t_game *game)
{
	int     x;
	int		y;

	game->collectable_score = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
    	{
			mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->tile_w * x, game->tile_h * y);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, game->tile_w * x, game->tile_h * y);
			else if (game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->collectable_img, game->tile_w * x, game->tile_h * y);
				game->collectable_score += 1;
			}
			else if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->tile_w * x, game->tile_h * y);
				game->player_x = game->tile_w * x;
				game->player_y = game->tile_h * y;
			}
			x++;
    	}
		y++;
	}
}

int	move_check(t_game *game)
{
	int map_x;
	int map_y;

	map_x = game->player_x / game->tile_w;
	map_y = game->player_y / game->tile_h;

	if (game->map[map_y][map_x] == '1')
		return (1);
	else if (game->map[map_y][map_x] == 'C')
		return (game->map[map_y][map_x] = '0', game->collectable_score -= 1, 0);
	return (0);
}

char *get_collectable_score(t_game *game)
{
	char	*score_str;

	score_str = ft_itoa(game->collectable_score);
	return (score_str);
}

void move_player(char c, t_game *game)
{
	char *score_str;

	score_str = get_collectable_score(game);
	// Clear the background where the score is drawn
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, 300, 32);

	if (c == 'r')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x - 32, game->player_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x, game->player_y);
	}
	else if (c == 'l')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x + 32, game->player_y); 
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x, game->player_y);
	}
	else if (c == 'u')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x, game->player_y + 32); 
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x, game->player_y);
	}
	else if (c == 'd')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x, game->player_y - 32); 
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x, game->player_y);
	}
	
	mlx_string_put(game->mlx, game->win, 300, 45, 0x000000, score_str);
	free(score_str);
}

int keypress(int keycode, t_game *game)
{
	int	move;

	if (keycode == KEY_RIGHT)
	{
		game->player_x += 32;
		move = move_check(game);
		if (move == 0)
			return (move_player('r', game), 0);
		game->player_x -= 32;
	}
	if (keycode == KEY_LEFT)
	{
		game->player_x -= 32;
		move = move_check(game);
		if (move == 0)
			return (move_player('l', game), 0);
		game->player_x += 32;
	}
	if (keycode == KEY_UP)
	{
		game->player_y -= 32;
		move = move_check(game);
		if (move == 0)
			return (move_player('u', game), 0);
		game->player_y += 32;
	}
	if (keycode == KEY_DOWN)
	{
		game->player_y += 32;
		move = move_check(game);
		if (move == 0)
			return (move_player('d', game), 0);
		game->player_y -= 32;
	}
	return (0);
}

int	main(void)
{
	t_game	game;
    int     x;
	int		y;
	int		size;
    char    *line;

	game.mlx = mlx_init();
	size = get_map_size(&game);
	game.map = malloc(sizeof(char *) * size);
	game.fd = open("maps/map1.ber", O_RDONLY);
    line = get_next_line(game.fd);
	game.map[0] = line;
	y = 1;
	while (line)
	{
		line = get_next_line(game.fd);
		game.map[y] = line;
		y++;
	}
	close(game.fd);
	game.win_width = (game.line_len - 1) * 32;
	game.win_height = y * 32;
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height - 32, "Ana Game!");
    game.wall_img = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.img_width, &game.img_height);
	game.grass_img = mlx_xpm_file_to_image(game.mlx, "textures/grass.xpm", &game.img_width, &game.img_height);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "textures/player.xpm", &game.img_width, &game.img_height);
    game.collectable_img = mlx_xpm_file_to_image(game.mlx, "textures/collectable.xpm", &game.img_width, &game.img_height);
	game.tile_w = game.img_width;
	game.tile_h = game.img_height;
	draw_map(&game);
	game.collectable_str = get_collectable_score(&game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
    return (0);
}
