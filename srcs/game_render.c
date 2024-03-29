/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:19:54 by ricardovala       #+#    #+#             */
/*   Updated: 2023/11/02 12:34:29 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	end_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clean_map(game);
	exit(1);
}

void	cat_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.exitcat.img, x
		* game->sprites.exitcat.width, y * game->sprites.exitcat.height);
}

void	set_game_sprites(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall.img, x
			* game->sprites.wall.width, y * game->sprites.wall.height);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.floor.img, x
			* game->sprites.floor.width, y * game->sprites.floor.height);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.collectible.img, x * game->sprites.collectible.width,
			y * game->sprites.collectible.height);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.player.img,
			x * game->sprites.player.width, y * game->sprites.player.height);
	if ((game->map[y][x] == 'P' && game->new_block == 'E')
		|| (game->map[y][x] == 'P' && game->been_in_exit == 1))
		cat_exit(game, x, y);
	if (game->map[y][x] == 'E'
		&& game->collectibles != game->collectibles_ingame)
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit.img, x
			* game->sprites.exit.width, y * game->sprites.exit.height);
	if (game->map[y][x] == 'E'
		&& game->collectibles == game->collectibles_ingame)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.openexit.img, x * game->sprites.openexit.width, y
			* game->sprites.openexit.height);
}

void	set_game_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			set_game_sprites(game, x, y);
			x++;
		}
		y++;
	}
}

void	set_game_data(t_game *game)
{
	game->collectibles = 0;
	game->collectibles_cmp = 0;
	game->collectibles_ingame = 0;
	game->exit = 0;
	game->exit_comp = 0;
	game->been_in_exit = 0;
	game->player = 0;
	game->flood_fill = 0;
	game->moves = 0;
	game->old_x = 0;
	game->old_y = 0;
	game->new_block = 0;
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = height(game->map);
	find_pos(game);
}
