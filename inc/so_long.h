/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/17 18:55:17 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_mac/mlx.h"
#include "../srcs/libft/inc/libft.h"
//Linux keycodes
#ifdef __linux__
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define A 97
#define W 119
#define S 115
#define D 100
#define ESC 65307
#endif

//Mac keycodes
#ifdef __APPLE__
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define A 0
#define W 13
#define S 1
#define D 2
#define ESC 53
#endif
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