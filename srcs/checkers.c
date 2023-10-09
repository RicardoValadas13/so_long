/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:32:57 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/06 18:33:41 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


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

static int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

static	int check_rect(char **map, t_map map_ram)
{
	int i;
	int j;

	i = 0;
	while (i < map_ram.height - 1)
	{
		j = 0;
		while (j < map_ram.width - 1)
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == '1')
				j++;	
			else
				return (0);
		}
		i++;
	}
	return (1);
}

/* static	int check_path(char **map, t_map map_ram)
{
	// Here I have to implement the flood fill recursive algorithm
} */

int	validate_map(char **map, t_map map_ram)
{
	map_ram.width = ft_strlen(map[0]);
	map_ram.height = height(map);
	printf("Width : %d\nHeight : %d\n", map_ram.width, map_ram.height);
	if (check_walls(map, map_ram) == 0)
		printf ("Error_walls\n");
	if (check_rect(map, map_ram) == 0)
	{
		printf ("Erro_rectangle\n");
		return (0);
	}
	/* if (!check_path(map, map_ram))
		return (0); */
	return (1);
}