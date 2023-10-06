/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/06 16:18:12 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	**append(char *tmp_str, int fd)
{
	char	*append;
	char	*map_str;
	char	**map_mx;

	while (1)
	{
		append = get_next_line(fd);
		if (append == NULL)
			break ;
		map_str = ft_strjoin(tmp_str, append);
		free(tmp_str);
		tmp_str = ft_strdup(map_str);
	}
	map_mx = ft_split(map_str, '\n');
	return (map_mx);
}

static	check_walls(char **map, t_map map_ram)
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

static	check_rect(char **map, t_map map_ram)
{
}

static	check_path(char **map, t_map map_ram)
{
	// Here I have to implement the flood fill recursive algorithm
}

int	validate_map(char **map, t_map map_ram)
{
	map_ram.width = ft_strlen(map[0]);
	map_ram.height = height(map);
	printf("Width : %s\nHeight : %s\n", map_ram.width, map_ram.height);
	if (!check_walls(map, map_ram))
		return (0);
	if (!check_rect(map, map_ram))
		return (0);
	if (!check_path(map, map_ram))
		return (0);
}

int	main(int ac, char **av)
{
	t_map	map_ram;
	int		fd;
	char	*first_line;
	char	**map;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	first_line = get_next_line(fd);
	map = append(first_line, fd);
	map_ram.width = ft_strlen(map[0]);
	map_ram.height = height(map);
	printf("Width : %d\nHeight : %d\n", map_ram.width, map_ram.height);
	if (!validate_map(map, map_ram))
		;
	return (1);
}
