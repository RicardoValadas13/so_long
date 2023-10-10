/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/09 15:01:44 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <libft.h>

typedef struct  s_map
{
    int width;
    int height;
    int exit;
    int exit_comp;
    int collectible;
    int collectible_comp;
    int player;
    int player_x;
    int player_y;
    int flood_fill;
}   t_map;

int main(int ac, char **av);
char **append(char *tmp_str, int fd);
int	validate_map(char **map);
void print_map(char **map);
int	height(char **map);
void find_pos(char **map, t_map *map_ram);
void set_ram(char **map, t_map *map_ram);
char **map_cpy(char **map, t_map map_ram);


#endif