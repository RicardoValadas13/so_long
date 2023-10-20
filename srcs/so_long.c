/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:58:06 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/19 18:49:39 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		return (1);
	file_format(av[1]);
	fd = open(av[1], O_RDONLY);
	game.map = append(fd);
	set_game_data(&game);
	if (validate_map(&game) == 0)
		error_msg("Invalid map\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height
		* 32, "So_Long");
	set_sprites(&game);
	set_game_window(&game);
	mlx_hook(game.win, 02, (1L << 0), key_hook, &game);
	mlx_loop(game.mlx);
	clean_map(&game);
	close(fd);
	return (0);
}
