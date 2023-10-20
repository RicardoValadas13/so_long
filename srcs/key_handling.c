/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:30 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/19 17:20:48 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == RIGHT || keycode == D)
		new_x++;
	if (keycode == LEFT || keycode == A)
		new_x--;
	if (keycode == UP || keycode == W)
		new_y--;
	if (keycode == DOWN || keycode == S)
		new_y++;
	if (keycode == ESC)
		end_game(game);
	move_player(game, new_x, new_y);
	set_game_window(game);
	return (0);
}
