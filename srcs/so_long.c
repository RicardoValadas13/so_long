/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/17 18:55:42 by ricardovala      ###   ########.fr       */
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

int	key_hook(int keycode, t_game *game)
{
	(void)game;
	printf("%d\n",keycode);
	if (keycode == RIGHT || keycode == D)
			return (0);
	if (keycode == LEFT || keycode == A)
			return (0);
	if (keycode == UP || keycode == W)
			return (0);
	if (keycode == DOWN || keycode == S)
			return (0);
	if (keycode == ESC)
			end_game(game);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map_ram;
	t_game	game;

	if (ac != 2)
		return (1);
	file_format(av[1]);
	fd = open(av[1], O_RDONLY);
	game.map = append(fd);
	set_ram(game.map, &map_ram);	
	if (validate_map(game.map, map_ram) == 0)
		error_msg("Invalid map\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map_ram.width * 32, map_ram.height * 32 , "So_Long");	
	
	set_sprites(&game);
	set_game(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	clean_map(game.map, map_ram.height);
	close(fd);
	return (0);
}
