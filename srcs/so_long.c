/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/17 19:49:39 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	set_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{	
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall.img, x * game->sprites.wall.width, y * game->sprites.wall.height);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.space.img, x * game->sprites.space.width, y * game->sprites.space.height);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.collectible.img, x * game->sprites.collectible.width, y * game->sprites.collectible.height);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.player.img, x * game->sprites.player.width, y * game->sprites.player.height);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit.img, x * game->sprites.exit.width, y * game->sprites.exit.height);
		x++;
		}
		y++;
	}
}

void	end_game(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (1);
}

void move_player(t_game *game, int new_x, int new_y) 
{
	char	new_pos;

	new_pos = game->map[new_y][new_x];
	if (new_pos == '0' || new_pos == 'C') 
	{
		if (new_pos == 'C') 
			game->collectibles_ingame++;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[new_y][new_x] = 'P';
	}
	if (new_pos == 'E')
	{
		if (game->collectibles_ingame == game->collectibles_cmp)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_x = new_x;
			game->player_y = new_y;
			game->map[new_y][new_x] = 'P';
			printf("You Won\n");
			end_game(game);
		}
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_x = new_x;
			game->player_y = new_y;
			game->map[new_y][new_x] = 'P';
		}
	}
}


int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;
	
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == RIGHT || keycode == D)
			new_x++;
	if (keycode == LEFT || keycode == A)
			new_x--;
	if (keycode == UP || keycode == W)
			new_y--;
	if (keycode == DOWN || keycode == S)
			new_y++;
	if (keycode == ESC)
			end_game(game);
	move_player(game, new_x, new_y);
	set_game(game);
	return (0);
}


int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		return (1);
	file_format(av[1]);
	fd = open(av[1], O_RDONLY);
	game.map = append(fd);
	set_game_data(&game);
	if (validate_map(&game) == 0)
		error_msg("Invalid map\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height * 32 , "So_Long");	
	set_sprites(&game);
	set_game(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	clean_map(&game);
	close(fd);
	return (0);
}
