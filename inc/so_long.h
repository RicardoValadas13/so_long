/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/17 19:48:09 by ricardovala      ###   ########.fr       */
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
	char	**map;
	int	map_width;
	int	map_height;
	int	player;
	int	player_x;
	int	player_y;
	int exit;
	int exit_comp;
	int	collectibles;
	int	collectibles_cmp;
	int	collectibles_ingame;
	int	flood_fill;
	int	win_condition;
	t_sprites	sprites;
}	t_game;

char **append(int fd);
int	validate_map(t_game	*game);
void print_map(char **map);
int	height(char **map);
void find_pos(t_game *game);
char **map_cpy(t_game *game);
void	clean_map(t_game *game);
void    set_sprites(t_game *game);
void	error_msg(char *str);
void	file_format(char *str);
void	clean_mapcpy(char **map, t_game *game);
void set_game_data(t_game *game);

#endif