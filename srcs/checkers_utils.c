/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:59:46 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/18 13:18:23 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void find_pos(t_game *game)
{
    int y;
    int x;
    
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
}

char **map_cpy(t_game *game)
{
	char **cpy_map;
	int i;

    i = 0;
    cpy_map = ft_calloc(sizeof (char *), game->map_height + 1);
    if(!cpy_map)
        return (NULL);
    while (i < game->map_height)
    {
        cpy_map[i] = ft_strdup(game->map[i]);
        i++;
    }
    return(cpy_map);
}
void set_game_data(t_game *game)
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
