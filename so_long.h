/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:24 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/26 17:39:20 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>

# define UP XK_w
# define DOWN XK_s
# define LEFT XK_a
# define RIGHT XK_d
# define ESC XK_Escape

//GAME ELEMENTS
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define ENEMY 'N'
# define EXIT 'E'

# define IMG_WIDTH 40
# define IMG_HEIGHT 40

//STRUCTURES
typedef struct s_coord
{
	int	x;//col
	int	y;//row
}	t_coord;

typedef struct s_sprites
{
	void	*img;
	void	*player;
	void	*floor;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*exit_2;
	void	*enemy;
}	t_sprites;	

typedef struct s_mappa
{
	char	**map_mat;
	int		collectible;
	int		ff_collect;
	int		ff_exit;
	t_coord	size;
	t_coord	exit;
	t_coord	player;
}	t_mappa;

//principale
typedef struct s_mlx_win
{
	void		*mlx;
	void		*mlx_win;
	void		*window;
	t_sprites	spr;
	t_coord		size;
	t_mappa		map;

	uint64_t	moves;
}	t_mlx_win;

//clean file
void	ft_free_matrix(char **map_mat);
int		ft_exit(t_mlx_win *window, char *str, int flag);
int		free_exit(t_mlx_win *window, int flag);
int		ez_exit(t_mlx_win *win);

//general
void	ft_print_matrix(char **map_mat);
int		ft_matlen(char **map_mat);
char	**mat_copy(char **mat, int rows);
int		ft_yesorno(char **map, t_coord pos);

//main
void	init_sprites(t_mlx_win *game);
int		gnl_countlines(char *map);
char	**get_map_matrix(char *map, int fd);

//checks file
int		basic_check(char *str);
void	map_checks(t_mlx_win *window, int rows, int cols);

//parsing file
int		check_if_dir(t_mlx_win *window, int argc, char *argv[]);
int		check_lines(int rows, int cols, char **map_mat);
int		check_walls(char **map_mat, int rows, int cols);
int		count_elements(int rows, int cols, char **map, char to_check);
int		check_elements(int rows, int cols, t_mlx_win *game);

//rendering file
void	*convert_image(t_mlx_win *window, char *c, int x, int y);
void	upload_image(t_mlx_win *window, void *c, int x, int y);
int		render_and_place(t_mlx_win *window);

//movement
int		key_event(int key, t_mlx_win *window);
int		strolling_around(t_mlx_win *window, t_coord pos);

#endif