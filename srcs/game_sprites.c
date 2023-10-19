#include "../inc/so_long.h"

void	set_sprites(t_game *game)
{
	game->sprites.wall1.img = mlx_xpm_file_to_image(game->mlx, "imgs/wall1.xpm",
		&game->sprites.wall1.width, &game->sprites.wall1.height);
	game->sprites.wall2.img = mlx_xpm_file_to_image(game->mlx, "imgs/wall2.xpm",
		&game->sprites.wall2.width, &game->sprites.wall2.height);
	game->sprites.player.img = mlx_xpm_file_to_image(game->mlx,
		"img/player.xpm", &game->sprites.player.width,
		&game->sprites.player.height);
	game->sprites.collectible.img = mlx_xpm_file_to_image(game->mlx,
		"img/collectible.xpm", &game->sprites.collectible.width,
		&game->sprites.collectible.height);
	game->sprites.exit.img = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm",
		&game->sprites.exit.width, &game->sprites.exit.height);
	game->sprites.openexit.img = mlx_xpm_file_to_image(game->mlx,
		"imgs/openexit.xpm", &game->sprites.openexit.width,
		&game->sprites.openexit.height);
	game->sprites.floor.img = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm",
		&game->sprites.floor.width, &game->sprites.floor.height);
}
