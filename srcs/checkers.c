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

static	int check_rect(char **map, t_map map_ram)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
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

static int check_doubles(char **map, t_map map_ram)
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
				map_ram.collectible++; 
			else if (map[i][j] == 'P') 
				map_ram.player++;
			else if (map[i][j] == 'E')
				map_ram.exit++;
			j++;
		}
		i++;
	}
	if(map_ram.exit > 1 || map_ram.collectible > 1 || map_ram.player > 1)
		return (0);
	return (1);
}

/* static	int check_path(char **map, t_map map_ram)
{
	int c;
	int e;

	c = 0;
	e = 0;
	if (c == map_ram.collectible && e == map_ram.exit)
		return (0);
	if (map[x][y] != 1)
} */
	
char **map_cpy(char **map, t_map map_ram)
{
	char **cpy_map;
	int i;

    i = 0;
    cpy_map = malloc(sizeof (char *) * map_ram.height);
    while (i < map_ram.height)
    {
        cpy_map[i] = malloc(sizeof (char *) * (map_ram.width + 1));
        ft_strlcpy(cpy_map[i], map[i], (map_ram.width + 1));
        i++;
    }
    return(cpy_map);
}

int	validate_map(char **map)
{
	t_map map_ram;

	set_ram(map, &map_ram);	
	if (check_rect(map, map_ram) == 0 ||check_content(map) == 0 ||
		 check_doubles(map, map_ram) == 0 || check_walls(map, map_ram) == 0)
		return (0);
    print_map(map_cpy(map, map_ram));
	/* if (!check_path(map_cpy(map, map_ram), map_ram))
		return (0); */
	return (1);
}