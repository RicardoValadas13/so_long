/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:35 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/19 17:20:36 by ricardovala      ###   ########.fr       */
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

void	find_pos(t_game *game)
{
	int	y;
	int	x;

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

char	**append(int fd)
{
	char	*append;
	char	*map_str;
	char	*tmp_str;
	char	**map_mx;

	map_str = NULL;
	while (1)
	{
		append = get_next_line(fd);
		if (append == NULL)
			break ;
		else if (*append == '\n')
		{
			free(append);
			free(map_str);
			return (NULL);
		}
		tmp_str = map_str;
		map_str = ft_strjoin(map_str, append);
		free(append);
		free(tmp_str);
	}
	if (map_str)
	{
		map_mx = ft_split(map_str, '\n');
		free(map_str);
	}
	else
		return (NULL);
	return (map_mx);
}
