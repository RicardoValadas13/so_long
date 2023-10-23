/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:19:54 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/20 19:30:03 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_img(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->sprites.wall.img);
	mlx_destroy_image(game->mlx, game->sprites.exit.img);
	mlx_destroy_image(game->mlx, game->sprites.collectible.img);
	mlx_destroy_image(game->mlx, game->sprites.floor.img);
	mlx_destroy_image(game->mlx, game->sprites.openexit.img);
	mlx_destroy_image(game->mlx, game->sprites.player.img);

}
int	end_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(1);
}

void	player_animation(t_game *game, int x, int y)
{
	printf("New block: %c\n", game->new_block);
	if (x - game->old_x > 0 && game->new_block != '1')
	{
		if (game->new_block != 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.animright.img,
				x * game->sprites.animright.width, y * game->sprites.animright.height);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exitcatright.img,
				x * game->sprites.exitcatright.width, y * game->sprites.exitcatright.height);
	}
	if (x - game->old_x < 0 && game->new_block != '1')
	{
		if (game->new_block != 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.animleft.img,
				x * game->sprites.animleft.width, y * game->sprites.animleft.height);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exitcatleft.img,
				x * game->sprites.exitcatleft.width, y * game->sprites.exitcatleft.height);
	}
	if (y - game->old_y > 0 && game->new_block != '1')
	{
		if (game->new_block != 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.animdown.img,
				x * game->sprites.animdown.width, y * game->sprites.animdown.height);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exitcatdown.img,
				x * game->sprites.exitcatdown.width, y * game->sprites.exitcatdown.height);
	}
	if (y - game->old_y < 0 && game->new_block != '1')
	{
		if (game->new_block != 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.animup.img,
				x * game->sprites.animup.width, y * game->sprites.animup.height);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exitcatup.img,
				x * game->sprites.exitcatup.width, y * game->sprites.exitcatup.height);
	}
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
		player_animation(game, x, y);
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
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = height(game->map);
	find_pos(game);
}
