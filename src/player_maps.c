/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:52:16 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/25 14:23:28 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game *game)
{
	int		fd;
	int		eof;
	char	*map;

	eof = 1;
	game->lin = 1;
	game->flsz = 0;
	fd = open(game->mappath, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Invalid file descriptor!\n"), exit(0), 0);
	while (eof > 0)
	{
		map = ft_calloc(1, 1);
		eof = read(fd, map, 1);
		if (*map == '\n')
			game->lin++;
		game->flsz++;
		free (map);
	}
	game->col = (game->flsz - game->lin) / game->lin;
	game->flsz--;
	close(fd);
	return (0);
}

char	*ft_readfile(char *filename)
{
	char	buff[100];
	int		read_count;
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_strdup("");
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buff, 100);
		buff[read_count] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	if (close(fd) == -1)
		return (NULL);
	return (str);
}

// map reading
int	read_map(t_game *game)
{
	game->map = ft_readfile(game->mappath);
	return (0);
}

// message about the possibility to leave the map
int	check_win_condition(t_game *game)
{
	if (game->arts.qtcollect == 0)
	{
		ft_printf("You can leave the map!\n");
		game->arts.qtcollect = -1;
	}
	return (0);
}

int	check_empty_map(t_game *game)
{
	if (game->flsz == 0)
	{
		return (ft_printf("Error\nMap file is empty.\n"),
			exit(0), 0);
	}
	return (0);
}
