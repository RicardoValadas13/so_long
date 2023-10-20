/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:32:57 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/19 18:49:46 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_map(t_game *game)
{
	char **cpy_map;
	cpy_map = map_cpy(game);
	if (check_rect(cpy_map, game) == 0 || check_content(cpy_map) == 0
		|| check_doubles(cpy_map, game) == 0 || check_walls(cpy_map, game) == 0)
		return (0);
	check_path(cpy_map, game->player_y, game->player_x, game);
	if (game->flood_fill == 0)
	{
		clean_mapcpy(cpy_map, game);
		return (0);
	}
	clean_mapcpy(cpy_map, game);
	return (1);
}