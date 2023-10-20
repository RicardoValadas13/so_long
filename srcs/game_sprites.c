/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:19:59 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/19 17:20:00 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_sprites(t_game *game)
{
	game->sprites.wall.img = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
		&game->sprites.wall.width, &game->sprites.wall.height);
	game->sprites.exitcat.img = mlx_xpm_file_to_image(game->mlx, "imgs/exit-cat.xpm",
		&game->sprites.exitcat.width, &game->sprites.exitcat.height);
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
}
