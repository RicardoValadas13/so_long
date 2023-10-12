/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/09 13:23:01 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		printf("\n");
		i++;
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
		tmp_str = map_str;
		map_str = ft_strjoin(map_str, append);
		free(append);
		free(tmp_str);
	}
	map_mx = ft_split(map_str, '\n');
	free(map_str);
	return (map_mx);
}

void	clean_map(char **map, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free (map);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**map;
	void	*mlx;
	t_map	map_ram;

	if (ac == 2)
	{
		mlx = mlx_init();
		fd = open(av[1], O_RDONLY);
		map = append(fd);
		set_ram(map, &map_ram);	
		if (validate_map(map, map_ram) == 0)
			printf ("Error\n");
		clean_map(map, map_ram.height);
		close(fd);
		return (1);
	}
	(void)mlx;
	return (1);
}
