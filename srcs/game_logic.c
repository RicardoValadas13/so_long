#include "../inc/so_long.h"

void	change_block(t_game *game, int new_x, int new_y, char c)
{
	game->map[game->player_y][game->player_x] = c;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	new_pos;

	new_pos = game->map[new_y][new_x];
	if (new_pos == '0' || new_pos == 'C')
	{
		if (new_pos == 'C')
			game->collectibles_ingame++;
		if (game->been_in_exit == 1)
		{
			change_block(game, new_x, new_y, 'E');
			game->been_in_exit = 0;
		}
		else
			change_block(game, new_x, new_y, '0');
	}
	if (new_pos == 'E')
	{
		if (game->collectibles_ingame == game->collectibles)
		{
			change_block(game, new_x, new_y, '0');
			end_game(game);
		}
		else
		{
			change_block(game, new_x, new_y, '0');
			game->been_in_exit++;
		}
	}
}
