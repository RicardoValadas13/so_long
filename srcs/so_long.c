/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/06 18:33:36 by ricardovala      ###   ########.fr       */
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
	if (validate_map(map, map_ram) == 0)
		printf ("error\n");
	return (1);
}
