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
	while (line && size++)
		line = get_next_line(game->fd);
	close(game->fd);
	game->map = malloc(sizeof(char *) * size);
	if (!game->map)
		return (0);
	game->fd = open("maps/map1.ber", O_RDONLY);
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

int	close_window()
{
	exit(0);
	return (0);
}

void	put_image_map(int y, int x, t_game *game)
{
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
			mlx_put_image_to_window(game->mlx, game->win, game->player_front_img, game->tile_w * x, game->tile_h * y);
			game->player_x = game->tile_w * x;
			game->player_y = game->tile_h * y;
		}
		else if (game->map[y][x] == 'E')
		{
			game->exit_x = game->tile_w * x;
			game->exit_y = game->tile_h * y;
			mlx_put_image_to_window(game->mlx, game->win, game->exit_img, game->exit_x, game->exit_y);
		}
		x++;
	}
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
		put_image_map(y, x, game);
		y++;
	}
}

void game_win(t_game *game)
{
	game->game_win = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x, game->player_y);
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->exit_x, game->exit_y);
	mlx_put_image_to_window(game->mlx, game->win, game->win2_img, 300, 300);
}

int	move_check(t_game *game)
{
	int map_x;
	int map_y;

	game->game_win = 0;
	map_x = game->new_player_x / game->tile_w;
	map_y = game->new_player_y / game->tile_h;

	if (game->collectable_score == 0 && game->map[map_y][map_x] == 'E')
		return(game_win(game), 1);
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == 'E')
		return (1);
	else if (game->map[map_y][map_x] == 'C')
		return (game->map[map_y][map_x] = '0', game->collectable_score -= 1, 0);
	return (0);
}

char *get_score(int score)
{
	char	*score_str;

	score_str = ft_itoa(score);
	return (score_str);
}

void move_player(t_game *game)
{
	char *move_str;

	mlx_put_image_to_window(game->mlx, game->win, game->score_back_img, 300, game->map_height);
	move_str = get_score(game->movements);
	mlx_string_put(game->mlx, game->win, 550, game->map_height + 70, 0xFFFFFF, move_str);
	ft_printf("Movements = %d\n", game->movements);
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x, game->player_y); 
	mlx_put_image_to_window(game->mlx, game->win, game->player_front_img, game->new_player_x, game->new_player_y);
	game->movements += 1;
	game->player_x = game->new_player_x;
	game->player_y = game->new_player_y;
	free(move_str);
}

int keypress(int keycode, t_game *game)
{
	int	move;
	game->new_player_x = game->player_x;
	game->new_player_y = game->player_y;

	if (game->game_win)
		return (0);
	if (game->collectable_score == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->open_exit_img, game->exit_x, game->exit_y);
	if (keycode == KEY_RIGHT)
		game->new_player_x += 32;
	else if (keycode == KEY_LEFT)
		game->new_player_x -= 32;
	else if (keycode == KEY_UP)
		game->new_player_y -= 32;
	else if (keycode == KEY_DOWN)
		game->new_player_y += 32;
	move = move_check(game);
	if (move == 0)
		return (move_player(game), 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int		size;

	game.mlx = mlx_init();
	size = get_map_size(&game);
	game.map_height = (size - 1) * 32;
	game.win_width = (game.line_len - 1) * 32;
	game.win_height = game.map_height + (3 * 32);
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, "Ana Game!");
    game.wall_img = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.img_width, &game.img_height);
	game.grass_img = mlx_xpm_file_to_image(game.mlx, "textures/grass.xpm", &game.img_width, &game.img_height);
	game.player_front_img = mlx_xpm_file_to_image(game.mlx, "textures/player_front.xpm", &game.img_width, &game.img_height);
	game.score_back_img = mlx_xpm_file_to_image(game.mlx, "textures/moves_score.xpm", &game.img_width, &game.img_height);
	game.player_back_img = mlx_xpm_file_to_image(game.mlx, "textures/player_back.xpm", &game.img_width, &game.img_height);
	game.player_right_img = mlx_xpm_file_to_image(game.mlx, "textures/player_right.xpm", &game.img_width, &game.img_height);
	game.player_left_img = mlx_xpm_file_to_image(game.mlx, "textures/player_left.xpm", &game.img_width, &game.img_height);
	game.win2_img = mlx_xpm_file_to_image(game.mlx, "textures/win2.xpm", &game.img_width, &game.img_height);
	game.collectable_img = mlx_xpm_file_to_image(game.mlx, "textures/collectable.xpm", &game.img_width, &game.img_height);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "textures/door.xpm", &game.img_width, &game.img_height);
	game.open_exit_img = mlx_xpm_file_to_image(game.mlx, "textures/open_door.xpm", &game.img_width, &game.img_height);
	game.tile_w = game.img_width;
	game.tile_h = game.img_height;
	game.movements = 0;
	draw_map(&game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
    return (0);
}
