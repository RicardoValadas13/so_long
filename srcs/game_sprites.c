/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:19:59 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/20 19:23:31 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_sprites(t_game *game)
{
	game->sprites.wall.img = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
		&game->sprites.wall.width, &game->sprites.wall.height);
	game->sprites.player.img = mlx_xpm_file_to_image(game->mlx,
		"img/cat.xpm", &game->sprites.player.width,
		&game->sprites.player.height);
	game->sprites.collectible.img = mlx_xpm_file_to_image(game->mlx,
		"img/collectible.xpm", &game->sprites.collectible.width,
		&game->sprites.collectible.height);
	game->sprites.exit.img = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
		&game->sprites.exit.width, &game->sprites.exit.height);
	game->sprites.openexit.img = mlx_xpm_file_to_image(game->mlx,
		"img/exit-open.xpm", &game->sprites.openexit.width,
		&game->sprites.openexit.height);
	game->sprites.floor.img = mlx_xpm_file_to_image(game->mlx, "img/grass.xpm",
		&game->sprites.floor.width, &game->sprites.floor.height);
	set_animsprites(game);
}

void	set_animsprites(t_game *game)
{
	game->sprites.animdown.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/catdown.xpm", &game->sprites.animdown.width,
		&game->sprites.animdown.height);
	game->sprites.animup.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/catup.xpm", &game->sprites.animup.width,
		&game->sprites.animup.height);
	game->sprites.animleft.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/catleft.xpm", &game->sprites.animleft.width,
		&game->sprites.animleft.height);
	game->sprites.animright.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/catright.xpm", &game->sprites.animright.width,
		&game->sprites.animright.height);
	game->sprites.exitcatdown.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/exitcatdown.xpm", &game->sprites.exitcatdown.width,
		&game->sprites.exitcatdown.height);
	game->sprites.exitcatup.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/exitcatup.xpm", &game->sprites.exitcatup.width,
		&game->sprites.exitcatup.height);
	game->sprites.exitcatleft.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/exitcatleft.xpm", &game->sprites.exitcatleft.width,
		&game->sprites.exitcatleft.height);
	game->sprites.exitcatright.img = mlx_xpm_file_to_image(game->mlx,
		"imganim/exitcatright.xpm", &game->sprites.exitcatright.width,
		&game->sprites.exitcatright.height);
}
