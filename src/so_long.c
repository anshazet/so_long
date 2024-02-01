/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:49:40 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/26 09:12:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// key initialization

static int	key_hook(int keycode, t_game *game)
{
	static int	check_steps;

	check_steps = game->scr.scr;
	if (keycode == ESC)
		endgame(game);
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == D || keycode == A || keycode == W || keycode == S || \
	keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		image_to_window(game);
	if (game->scr.scr > check_steps)
		ft_printf("Steps = %d\n", game->scr.scr);
	return (0);
}

static int	init_game(t_game *game)
{
	game->scr.scr = 0;
	game->qtext = 0;
	game->arts.qtcollect = 0;
	game->hero.qthero = 0;
	return (0);
}

static void	main2(t_game *game)
{
	init_game(game);
	level_validation(game);
	check_surrounded(game);
	load_files(game);
	game->vrs.mlx = mlx_init();
	load_objects(game);
	game->vrs.mapw = game->col * game->tree.img_wid;
	game->vrs.maph = game->lin * game->tree.img_hght;
	game->vrs.win = mlx_new_window(game->vrs.mlx,
			game->vrs.mapw, game->vrs.maph, "SO_LONG");
	image_to_window(game);
	mlx_key_hook(game->vrs.win, key_hook, game);
	mlx_hook(game->vrs.win, 17, 0, endgame, game);
	mlx_hook(game->vrs.win, 0, 1, key_hook, game);
	mlx_expose_hook(game->vrs.win, image_to_window, game);
	mlx_loop(game->vrs.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERROR_DEF "Invalid parameters!\n"), 0);
	game.mappath = argv[1];
	ft_printf("Opening map: %s..\n", game.mappath);
	extension_check(&game);
	load_map(&game);
	read_map(&game);
	check_empty_map(&game);
	if (check_map_width(&game))
	{
		ft_printf("Error!\nMap is not rectangular\n");
		exit(0);
	}
	if (check_map2(&game))
	{
		ft_printf("Error!\nMap impossible\n");
		exit(0);
	}
	main2(&game);
	return (0);
}
