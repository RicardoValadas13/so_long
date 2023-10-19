/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/19 13:11:45 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_mac/mlx.h"
# include "../srcs/libft/inc/libft.h"
// Linux keycodes
# ifdef __linux__
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define A 97
#  define W 119
#  define S 115
#  define D 100
#  define ESC 65307
# endif

// Mac keycodes
# ifdef __APPLE__
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define A 0
#  define W 13
#  define S 1
#  define D 2
#  define ESC 53
# endif

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_sprites
{
	t_img		exit;
	t_img		openexit;
	t_img		collectible;
	t_img		player;
	t_img		wall1;
	t_img		wall2;
	t_img		floor;
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			player;
	int			player_x;
	int			player_y;
	int			exit;
	int			exit_comp;
	int			been_in_exit;
	int			collectibles;
	int			collectibles_cmp;
	int			collectibles_ingame;
	int			flood_fill;
	int			win_condition;
	int			moves;
	t_sprites	sprites;
}				t_game;

// checkers_utils.c functions
int				check_walls(char **map, t_game *game);
int				check_rect(char **map, t_game *game);
int				check_content(char **map);
int				check_doubles(char **map, t_game *game);
void			check_path(char **map, int y, int x, t_game *game);

// checkers.c functions
int				validate_map(t_game *game);

// error.c functions
void			error_msg(char *str);
void			clean_map(t_game *game);
void			file_format(char *str);
void			clean_mapcpy(char **map, t_game *game);
char			**map_cpy(t_game *game);

// game_logic.c functions
void			change_block(t_game *game, int new_x, int new_y, char c);
void			move_player(t_game *game, int new_x, int new_y);

// game_render.c functions
void			end_game(t_game *game);
void			set_game_window(t_game *game);
void			set_game_data(t_game *game);

// game_sprites.c functions
void			set_sprites(t_game *game);

// key_handling.c functions
int				key_hook(int keycode, t_game *game);

// so_long_utils.c
int				height(char **map);
char			**append(int fd);
void			find_pos(t_game *game);

int				key_hook(int keycode, t_game *game);

#endif