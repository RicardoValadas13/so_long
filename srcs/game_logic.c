/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:20 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/19 17:32:08 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	change_block(t_game *game, int new_x, int new_y, char c)
{
	game->map[game->player_y][game->player_x] = c;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

void	move_to_empty_block(t_game *game, int new_x, int new_y)
{
	change_block(game, new_x, new_y, '0');
}

void	move_to_collectible(t_game *game, int new_x, int new_y)
{
	game->collectibles_ingame++;
	move_to_empty_block(game, new_x, new_y);
}

void	move_to_exit(t_game *game, int new_x, int new_y)
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
void	move_player(t_game *game, int new_x, int new_y)
{
	char	new_pos;

	new_pos = game->map[new_y][new_x];

	if (new_pos == '0' && game->been_in_exit == 0)
		move_to_empty_block(game, new_x, new_y);
	if (new_pos == 'C' && game->been_in_exit == 0)
		move_to_collectible(game, new_x, new_y);
	if (game->been_in_exit == 1)
	{
		change_block(game, new_x, new_y, 'E');
		game->been_in_exit = 0;
	}
	if (new_pos == 'E')
		move_to_exit(game, new_x, new_y);
}
