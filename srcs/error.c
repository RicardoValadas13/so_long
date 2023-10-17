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

void	error_msg(char *str)
{
	write(2 , str, ft_strlen(str));
	exit (1);
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

void	file_format(char *str)
{
	char *cmp;

	cmp = ft_strchr(str, '.');
	if (ft_strncmp(".ber", cmp, ft_strlen(cmp)) != 0 && access(str, F_OK) == 0)
		error_msg("Incorrect file format\n");
	else if (access(str, F_OK) != 0)
		error_msg("File not found\n");
}