/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_impossible_maps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:26:50 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/26 09:13:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_game *game)
{
	int		x;
	int		y;
	int		path;
	char	c;

	ft_printf("Checking map path..\n");
	path = 0;
	y = 0;
	while (y <= game->map2_y)
	{
		x = 0;
		while (x <= game->map2_x)
		{
			c = game->map2[x][y];
			ft_printf("%c", c);
			if (c == 'P' || c == 'C' || c == 'E')
			path = -1;
			x++;
		}
		ft_printf("\n");
		y++;
	}
	return (path);
}

//recursive function to make a path
void	make_path(t_game *game, int x, int y)
{
	if (x >= 0 && x < game->map2_x && y >= 0 && y < game->map2_y)
	{
		if (game->map2[x][y] != '1' && game->map2[x][y] != '*')
		{
			game->map2[x][y] = '*';
			make_path(game, x + 1, y);
			make_path(game, x - 1, y);
			make_path(game, x, y + 1);
			make_path(game, x, y - 1);
		}
	}
}

static void	copy_map2(int x, int y, t_game *game)
{
	game->map2_x = x - 1;
	game->map2_y = y;
	ft_printf("Loading map..\n");
	y = 0;
	while (y <= game->map2_y)
	{
		x = 0;
		while (x <= game->map2_x)
		{
			ft_printf("%c", game->map2[x][y]);
			if (game->map2[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

// copy map to map2 (from string to a double int matrix
void	copy_map(t_game *game)
{
	int	x;
	int	y;
	int	totalsize;

	totalsize = 0;
	x = 0;
	y = 0;
	while (totalsize < game->flsz)
	{
		game->map2[x][y] = game->map[totalsize];
		x++;
		if (game->map[totalsize++] == '\n')
		{
			x = 0;
			y++;
		}
	}
	copy_map2(x, y, game);
}

int	check_map_width(t_game *game)
{
	int		i;
	int		error;
	size_t	len;
	char	**map_tab;

	map_tab = ft_split (game->map, '\n');
	len = ft_strlen(map_tab[0]);
	i = 0;
	error = 0;
	while (map_tab[i])
	{
		if (ft_strlen(map_tab[i]) != len)
		error = 1;
		i++;
	}
	i = 0;
	while (map_tab[i])
	{
		free(map_tab[i]);
		i++;
	}
	free(map_tab);
	return (error);
}
