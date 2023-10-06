/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/06 15:37:17 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <libft.h>

typedef struct  s_map
{
    int width;
    int height;
}   t_map;

int main(int ac, char **av);
char **append(char *tmp_str, int fd);



#endif