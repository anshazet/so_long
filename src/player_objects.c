/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:53:02 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/25 14:35:16 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// put player

int	put_hero(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->hero.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// put tree

int	put_tree(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->tree.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// put ground

int	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// put collect

int	put_artefact(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->arts.img, (x * game->tree.img_wid + 12),
		(y * game->tree.img_hght + 12));
	return (0);
}

// put exit

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->exit.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}
