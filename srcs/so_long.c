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


int	main(int ac, char **av)
{
	int		fd;
	char	*first_line;
	char	**map;
	void	*mlx;

	
	if (ac == 2)
	{
		mlx = mlx_init();
		fd = open(av[1], O_RDONLY);
		first_line = get_next_line(fd);
		map = append(first_line, fd);
		if (validate_map(map) == 0)
			printf ("Error\n");
		return (1);
	}
	return (1);
}
