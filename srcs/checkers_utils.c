/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:59:46 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/19 13:07:07 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_walls(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_width)
	{
		if (map[0][j] != '1' || map[game->map_height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < game->map_height)
	{
		if (map[i][0] != '1' || map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rect(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_content(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'P' || map[i][j] == 'E')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_doubles(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->collectibles++;
			else if (map[i][j] == 'P')
				game->player++;
			else if (map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->exit != 1 || game->collectibles < 1 || game->player != 1)
		return (0);
	return (1);
}

void	check_path(char **map, int y, int x, t_game *game)
{
	if (map[y][x] == 'C')
		game->collectibles_cmp++;
	if (map[y][x] == 'E')
		game->exit_comp++;
	if (game->collectibles_cmp == game->collectibles
		&& game->exit_comp == game->exit)
	{
		game->flood_fill = 1;
		return ;
	}
	map[y][x] = 'D';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'D')
		check_path(map, y - 1, x, game);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'D')
		check_path(map, y + 1, x, game);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'D')
		check_path(map, y, x + 1, game);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'D')
		check_path(map, y, x - 1, game);
}
