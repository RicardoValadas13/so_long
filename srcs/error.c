#include "../inc/so_long.h"

void	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	clean_mapcpy(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	file_format(char *str)
{
	char	*cmp;

	cmp = ft_strchr(str, '.');
	if (ft_strncmp(".ber", cmp, ft_strlen(cmp)) != 0 && access(str, F_OK) == 0)
		error_msg("Incorrect file format\n");
	else if (access(str, F_OK) != 0)
		error_msg("File not found\n");
}
void	clean_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

char	**map_cpy(t_game *game)
{
	char	**cpy_map;
	int		i;

	i = 0;
	cpy_map = ft_calloc(sizeof(char *), game->map_height + 1);
	if (!cpy_map)
		return (NULL);
	while (i < game->map_height)
	{
		cpy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (cpy_map);
}
