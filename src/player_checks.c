/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:50:53 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/26 09:08:56 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check extention of the map

int	extension_check(t_game *game)
{
	int	size;

	size = ft_strlen(game->mappath) - 4;
	if (game->mappath[size] == '.' && game->mappath[size + 1] == 'b'
		&& game->mappath[size + 2] == 'e' && game->mappath[size + 3] == 'r')
		return (0);
	return (ft_printf("Invalid extension. Must be a \".ber\" file\n"),
		exit(0), 0);
}

int	check_map2(t_game *game)
{
	copy_map(game);
	make_path(game, game->player_x, game->player_y);
	return (check_path(game));
}
