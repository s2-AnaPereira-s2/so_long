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

void	put_image(int y, int x, t_game *game)
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
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->tile_w * x, game->tile_h * y);
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
		put_image(y, x, game);
		y++;
	}
}

void game_win(t_game *game)
{
	game->game_win = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->win_img, 300, 300);
}

int	move_check(t_game *game)
{
	int map_x;
	int map_y;
	int score_x;
	int score_y;
	int score2_x;
	int score2_y;

	map_x = game->new_player_x / game->tile_w;
	map_y = game->new_player_y / game->tile_h;
	score_x = game->score_back1_x / game->tile_w;
	score_y = game->score_back1_y / game->tile_h;
	score2_x = game->score_back2_x / game->tile_w;
	score2_y = game->score_back2_y / game->tile_h;

	if (game->collectable_score == 0 && game->map[map_y][map_x] == 'E')
		return(game_win(game), 0);
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == 'E' || (map_y == score_y && map_x == score_x) 
	|| (map_y == score2_y && map_x == score_x) || (map_y == score2_y && map_x == score2_x) 
	|| (map_y == score_y && map_x == score2_x))
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

	mlx_put_image_to_window(game->mlx, game->win, game->score_back_img, game->score_back1_x, game->score_back1_y);
	mlx_put_image_to_window(game->mlx, game->win, game->score_back_img, game->score_back1_x, game->score_back2_y);
	mlx_put_image_to_window(game->mlx, game->win, game->score_back_img, game->score_back2_x, game->score_back1_y);
	mlx_put_image_to_window(game->mlx, game->win, game->score_back_img, game->score_back2_x, game->score_back2_y);
	move_str = get_score(game->movements);
	mlx_string_put(game->mlx, game->win, game->score_back2_x, game->score_back1_y + 48, 0x000000, move_str);
	ft_printf("Movements = %d\n", game->movements);
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, game->player_x, game->player_y); 
	mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->new_player_x, game->new_player_y);
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
	game.win_height = (y + 3) * 32;
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, "Ana Game!");
    game.wall_img = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.img_width, &game.img_height);
	game.grass_img = mlx_xpm_file_to_image(game.mlx, "textures/grass.xpm", &game.img_width, &game.img_height);
	game.score_back_img = mlx_xpm_file_to_image(game.mlx, "textures/score_back.xpm", &game.img_width, &game.img_height);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "textures/player.xpm", &game.img_width, &game.img_height);
    game.win_img = mlx_xpm_file_to_image(game.mlx, "textures/win.xpm", &game.img_width, &game.img_height);
	game.collectable_img = mlx_xpm_file_to_image(game.mlx, "textures/collectable.xpm", &game.img_width, &game.img_height);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "textures/door.xpm", &game.img_width, &game.img_height);
	game.tile_w = game.img_width;
	game.tile_h = game.img_height;
	game.movements = 0;
	game.game_win = 0;
	game.score_back1_x = 480;
	game.score_back1_y = y * 32;
	game.score_back2_x = 512;
	game.score_back2_y = (y + 1) * 32;
	draw_map(&game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
    return (0);
}
