/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:51:27 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/25 13:41:58 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//error if the map not surrounded by forest 
//checks the first and last lines of the game map for valid wall placement

static int	frst_lst_line(t_game *game, int line, int col)
{
	if (line == 0)
		while (++col < game->col)
			if (game->map[col] != '1')
				return (ft_printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	if (line == game->lin)
	{
		col = ((game->flsz - 1) - (game->col - 1));
		while (++col < game->flsz)
			if (game->map[col] != '1')
				return (ft_printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	}
	return (0);
}

//check if the map are surrounded by forest

int	check_surrounded(t_game *game)
{
	int	c;
	int	l;

	l = 0;
	while (l <= game->lin)
	{
		c = -1;
		frst_lst_line(game, l, c);
		if (l == 1)
			if (game->map[game->col + l] != '1'
				|| game->map[game->col * 2] != '1')
				return (ft_printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		if (l > 0 && l < game->lin)
			if (game->map[((game->col + 1) * l)] != '1'
				|| game->map[game->col - 1 + ((game->col + 1) * (l))] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		l++;
	}
	return (0);
}

//check symbols on the map

static int	check_invalid_chars(t_game *game, int pos)
{
	char	*valid_chars;

	valid_chars = "PEC10\n";
	if (get_player(valid_chars, game->map[pos]) == NULL)
		return (ft_printf(ERROR_DEF PARAM_ERROR), free(game->map), exit(0), 0);
	else
		return (0);
}

// check map

static int	check_map_content(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->flsz - 1)
	{
		check_invalid_chars(game, i);
		if (game->map[i] == 'P')
			game->hero.qthero++;
		if (game->map[i] == 'E')
			game->qtext++;
		if (game->map[i] == 'C')
			game->arts.qtcollect++;
		i++;
	}
	return (0);
}

//errors in case if invalid parameters

int	level_validation(t_game *game)
{
	check_map_content(game);
	if (game->hero.qthero == 0)
		return (ft_printf(ERROR_DEF HERO_ERROR), free(game->map), exit(0), 0);
	if (game->hero.qthero > 1)
		return (ft_printf(ERROR_DEF ONE_HERO_ERROR), free(game->map),
			exit(0), 0);
	if (game->arts.qtcollect == 0)
		return (ft_printf(ERROR_DEF ART_ERROR), free(game->map), exit(0), 0);
	if (game->qtext == 0)
		return (ft_printf(ERROR_DEF EXIT_ERROR), free(game->map), exit(0), 0);
	if (game->qtext > 1)
		return (ft_printf(ERROR_DEF ONE_EXIT_ERROR), free(game->map),
			exit(0), 0);
	return (0);
}
