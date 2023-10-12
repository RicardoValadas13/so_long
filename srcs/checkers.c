/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:32:57 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/09 20:06:08 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


static	int check_walls(char **map, t_map map_ram)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_ram.width)
	{
		if (map[0][j] != '1' || map[map_ram.height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < map_ram.height)
	{
		if (map[i][0] != '1' || map[i][map_ram.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int check_rect(char **map, t_map map_ram)
{
	int i;
	int j;
	
	i = 0;
	while (i < map_ram.height)
	{
		j = 0;
		while(map[i][j])
			j++;
		if (j != map_ram.width)
			return (0); 
		i++;
	}
	return (1);
}

static int check_content(char **map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int check_doubles(char **map, t_map *map_ram)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				map_ram->collectible++; 
			else if (map[i][j] == 'P') 
				map_ram->player++;
			else if (map[i][j] == 'E')
				map_ram->exit++;
			j++;
		}
		i++;
	}
	if(map_ram->exit > 1 || map_ram->collectible > 1 || map_ram->player > 1)
		return (0);
	return (1);
}

static	void check_path(char **map, int y, int x, t_map *map_ram)
{
	/* print_map(map);
	printf("\n --- Flood Fill --- \n Position : x(%d)  y(%d)\n Collectible = %d\n Exit : %d\n", x, y, map_ram->collectible_comp, map_ram->exit_comp); */
	if (map[y][x] == 'C')
		map_ram->collectible_comp++;
	if (map[y][x] == 'E')
		map_ram->exit_comp++;
	if (map_ram->collectible_comp == map_ram->collectible && map_ram->exit_comp == map_ram->exit)
	{
		map_ram->flood_fill = 1;
		return ;
	}
	map[y][x] = 'D';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'D')
		check_path(map, y - 1, x, map_ram);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'D')
		check_path(map, y + 1, x, map_ram);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'D')
		check_path(map, y, x + 1, map_ram);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'D')
		check_path(map, y, x - 1, map_ram);
}

int	validate_map(char **map, t_map map_ram)
{
	char **cpy_map;

	cpy_map = map_cpy(map, map_ram);
	if (check_rect(cpy_map, map_ram) == 0 ||check_content(cpy_map) == 0 ||
		 check_doubles(cpy_map, &map_ram) == 0 || check_walls(cpy_map, map_ram) == 0)
		return (0);
    /* print_map(map_cpy(map, map_ram));
	printf("\nCollectibles : %d\nExit : %d\n", map_ram.collectible, map_ram.exit); */
	check_path(cpy_map, map_ram.player_y, map_ram.player_x, &map_ram);
	if (map_ram.flood_fill == 0)
	{
		clean_map(cpy_map, map_ram.height);
		return (0);
	}
	clean_map(cpy_map, map_ram.height);
	return (1);
}