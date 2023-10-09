/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:59:46 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/09 15:01:49 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void find_pos(char **map, t_map *map_ram)
{
    int y;
    int x;
    
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                map_ram->player_x = x;
                map_ram->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void set_ram(char **map, t_map *map_ram)
{
	map_ram->collectible = 0;
	map_ram->exit = 0;
	map_ram->player = 0;
	map_ram->width = ft_strlen(map[0]);
	map_ram->height = height(map);
    find_pos(map, map_ram);
}