/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/09 14:17:44 by ricardovala      ###   ########.fr       */
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
    int collectible;
    int player;
    int player_x;
    int player_y;
}   t_map;

int main(int ac, char **av);
char **append(char *tmp_str, int fd);
int	validate_map(char **map);
void print_map(char **map);



#endif