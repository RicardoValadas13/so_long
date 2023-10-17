/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/09 15:01:44 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../srcs/libft/inc/libft.h"

#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define A 97
#define W 119
#define S 115
#define D 100
#define ESC 65307

typedef struct  s_map
{
	int width;
	int height;
	int exit;
	int exit_comp;
	int collectible;
	int collectible_comp;
	int player;
	int player_x;
	int player_y;
	int flood_fill;
}	t_map;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct	s_sprites
{
	t_img	exit;
	t_img	collectible;
	t_img	player;
	t_img	wall;
	t_img	space;
}	t_sprites;

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	int	mvs;
	char	**map;
	t_sprites	sprites;
}	t_game;

char **append(int fd);
int	validate_map(char **map, t_map map_ram);
void print_map(char **map);
int	height(char **map);
void find_pos(char **map, t_map *map_ram);
void set_ram(char **map, t_map *map_ram);
char **map_cpy(char **map, t_map map_ram);
void	clean_map(char **map, int height);
void    set_sprites(t_game *game);
void	set_game(t_game *game);
void	error_msg(char *str);
void	file_format(char *str);


#endif