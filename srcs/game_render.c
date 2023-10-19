#include "../inc/so_long.h"

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
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
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.wall1.img, x * game->sprites.wall1.width, y
					* game->sprites.wall1.height);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.floor.img, x * game->sprites.floor.width, y
					* game->sprites.floor.height);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.collectible.img, x
					* game->sprites.collectible.width, y
					* game->sprites.collectible.height);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.player.img, x * game->sprites.player.width, y
					* game->sprites.player.height);
			if (game->map[y][x] == 'E'
				&& game->collectibles != game->collectibles_ingame)
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.exit.img, x * game->sprites.exit.width, y
					* game->sprites.exit.height);
			if (game->map[y][x] == 'E'
				&& game->collectibles == game->collectibles_ingame)
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.openexit.img, x
					* game->sprites.openexit.width, y
					* game->sprites.openexit.height);
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
