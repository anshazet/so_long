/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:50:18 by ashalagi          #+#    #+#             */
/*   Updated: 2023/04/26 09:25:24 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define W         119 
# define S       115
# define A       97
# define D      100

# define ESC        65307

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define ERROR_DEF  "Error\n"

# define ERROR_PLAYER		"Player should not be surrounded be the forest!\n"
# define ERROR_ARTEFACT		"Artefact should not be surrounded be the forest!\n"
# define ERROR_EXIT			"Exit should not be surrounded be the forest!\n"

# define HERO_ERROR			"Need a hero on the map!\n"
# define ONE_HERO_ERROR		"Only one hero allowed!\n"
# define ART_ERROR			"Need at least one artefact!\n"
# define EXIT_ERROR			"Need one exit!\n"
# define ONE_EXIT_ERROR		"Only one exit allowed!\n"
# define VLDMERROR			"Not a valid map!\n"
# define PARAM_ERROR			"Invalid parameter!\n"
# define WALL_ERR			"Map should be surrounded by forest!\n"
# define SQREERROR			"Map cannot be a square\n"
# define WINMSG				"You Won! Score: "
# define LEAVE				"You can close the game.\n"

# define HERO	"./textures/hero.xpm"
# define GROUND 	"./textures/ground.xpm"
# define TREE		"./textures/tree.xpm"
# define EXIT		"./textures/exit.xpm"
# define PUMPKIN		"./textures/pumpkin.xpm"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		maph;
	int		mapw;
}				t_vars;

typedef struct s_sprite{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
}				t_sprite;

typedef struct s_hero{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
	int		qthero;
}				t_hero;

typedef struct s_collect{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
	int		qtcollect;
}				t_collect;

typedef struct s_score{
	int		scr;
}				t_score;

typedef struct s_game{
	t_vars		vrs;
	t_score		scr;
	t_hero		hero;
	t_collect	arts;
	t_sprite	tree;
	t_sprite	ground;
	t_sprite	exit;
	int			qtext;
	int			flsz;
	int			col;
	int			lin;
	char		*map;
	int			map2[100][100];
	int			map2_x;
	int			map2_y;
	int			player_x;
	int			player_y;
	char		*mappath;
}				t_game;

char		*get_player(char *s, char c);
int			load_objects(t_game *game);
int			unload_objects(t_game *game);
int			load_files(t_game *game);
int			load_map(t_game *game);
int			read_map(t_game *game);
int			endgame(t_game *game);

int			put_tree(t_game *game, int x, int y);
int			put_ground(t_game *game, int x, int y);
int			put_hero(t_game *game, int x, int y);
int			put_artefact(t_game *game, int x, int y);
int			put_exit(t_game *game, int x, int y);

int			move_up(t_game *game);
int			move_down(t_game *game);
int			move_left(t_game *game);
int			move_right(t_game *game);

int			image_to_window(t_game *game);
int			images_letters(t_game *game, int size, int column, int line);

int			check_map2(t_game *game);
int			check_map_width(t_game *game);
int			check_empty_map(t_game *game);
void		copy_map(t_game *game);
void		make_path(t_game *game, int x, int y);
int			check_path(t_game *game);

int			extension_check(t_game *game);
int			check_surrounded(t_game *game);
int			level_validation(t_game *game);
int			check_win_condition(t_game *game);
int			finished(t_game *game);

#endif
