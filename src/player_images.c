/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:51:52 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/25 13:42:20 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// position of objects on thr map

int	images_letters(t_game *game, int size, int column, int line)
{	
	if (game->map[size] == '0')
		put_ground(game, column, line);
	if (game->map[size] == '1')
		put_tree(game, column, line);
	if (game->map[size] == 'P')
		put_hero(game, column, line);
	if (game->map[size] == 'C')
		put_artefact(game, column, line);
	if (game->map[size] == 'E')
		put_exit(game, column, line);
	return (1);
}

// loading objects into windows

int	image_to_window(t_game *game)
{
	int		line;
	int		column;
	int		totalsize;

	totalsize = 0;
	line = 0;
	column = 0;
	while (totalsize < game->flsz)
	{
		column += images_letters(game, totalsize, column, line);
		if (game->map[totalsize++] == '\n')
		{
			column = 0;
			line++;
		}
	}
	check_win_condition(game);
	return (0);
}
