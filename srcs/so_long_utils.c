/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:35 by ricardovala       #+#    #+#             */
/*   Updated: 2023/11/02 12:33:49 by ricardovala      ###   ########.fr       */
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

void	set_data(t_data *data)
{
	data->append = NULL;
	data->map_str = NULL;
	data->tmp_str = NULL;
	data->map_mx = NULL;
}

char	**append(int fd, t_data *data)
{
	while (1)
	{
		data->append = get_next_line(fd);
		if (data->append == NULL)
			break ;
		else if (ft_strncmp(data->append, "\n", ft_strlen(data->append)) == 0)
		{
			free(data->append);
			free(data->map_str);
			return (NULL);
		}
		data->tmp_str = data->map_str;
		data->map_str = ft_strjoin(data->map_str, data->append);
		free(data->append);
		free(data->tmp_str);
	}
	if (data->map_str)
	{
		data->map_mx = ft_split(data->map_str, '\n');
		free(data->map_str);
	}
	else
		return (NULL);
	return (data->map_mx);
}
