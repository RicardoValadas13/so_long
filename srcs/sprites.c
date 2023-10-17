#include "../inc/so_long.h"


void    set_sprites(t_game *game)
{

    	game->sprites.wall.img = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &game->sprites.wall.width, &game->sprites.wall.height);
	    /* sprite->addr = mlx_get_data_addr(sprite->img, sprite->bits_per_pixel, sprite->line_length,
		sprite->endian); */
    	game->sprites.player.img = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &game->sprites.player.width, &game->sprites.player.height);
    	game->sprites.collectible.img = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm", &game->sprites.collectible.width, &game->sprites.collectible.height);
    	game->sprites.exit.img = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &game->sprites.exit.width, &game->sprites.exit.height);
    	game->sprites.space.img = mlx_xpm_file_to_image(game->mlx, "img/space.xpm", &game->sprites.space.width, &game->sprites.space.height);
}