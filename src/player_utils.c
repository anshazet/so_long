/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:53:28 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/25 14:36:29 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// textures

int	load_files(t_game *game)
{
	game->hero.path = HERO;
	game->ground.path = GROUND;
	game->tree.path = TREE;
	game->exit.path = EXIT;
	game->arts.path = PUMPKIN;
	return (0);
}

// loading objects

int	load_objects(t_game *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->vrs.mlx, game->hero.path,
			&game->hero.img_wid, &game->hero.img_hght);
	game->tree.img = mlx_xpm_file_to_image(game->vrs.mlx, game->tree.path,
			&game->tree.img_wid, &game->tree.img_hght);
	game->ground.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ground.path,
			&game->ground.img_wid, &game->ground.img_hght);
	game->arts.img = mlx_xpm_file_to_image(game->vrs.mlx, game->arts.path,
			&game->arts.img_wid, &game->arts.img_hght);
	game->exit.img = mlx_xpm_file_to_image(game->vrs.mlx, game->exit.path,
			&game->exit.img_wid, &game->exit.img_hght);
	return (0);
}

// unloading objects

int	unload_objects(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->hero.img);
	mlx_destroy_image(game->vrs.mlx, game->ground.img);
	mlx_destroy_image(game->vrs.mlx, game->tree.img);
	mlx_destroy_image(game->vrs.mlx, game->arts.img);
	mlx_destroy_image(game->vrs.mlx, game->exit.img);
	return (0);
}

// game exit
int	endgame(t_game *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vrs.mlx, game->vrs.win);
	mlx_destroy_display(game->vrs.mlx);
	free(game->vrs.mlx);
	free(game->map);
	exit(0);
	return (0);
}

// player finishing

int	finished(t_game *game)
{
	ft_printf(WINMSG "%d\n", game->scr.scr);
	return (endgame(game), 1);
}
