/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:18:08 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/23 15:58:05 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <X11/X.h>

void	init_sprites(t_mlx_win *game)
{
	int	x;
	int	y;

	x = IMG_WIDTH;
	y = IMG_HEIGHT;
	game->spr.wall = convert_image(game, "./images/palm.xpm", x, y);
	game->spr.floor = convert_image(game, "./images/floor1.xpm", x, y);
	game->spr.player = convert_image(game, "./images/dolphin.xpm", x, y);
	game->spr.collectible = convert_image(game,
			"./images/collectible.xpm", x, y);
	game->spr.enemy = convert_image(game, "./images/enemy.xpm", x, y);
	game->spr.exit = convert_image(game, "./images/pc-off.xpm", x, y);
	game->spr.exit_2 = convert_image(game, "./images/pc-on.xpm", x, y);
}

int	gnl_countlines(char *map)
{
	int		fd;
	char	*map_line;
	int		mat_len;

	fd = open(map, O_RDONLY);
	mat_len = 0;
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		mat_len++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	close (fd);
	return (mat_len);
}

char	**get_map_matrix(char *map, int fd)
{
	char	**map_mat;
	char	*map_line;
	int		mat_len;
	int		i;

	mat_len = gnl_countlines(map);
	map_mat = ft_calloc(mat_len + 1, sizeof(char *));
	if (map_mat == NULL)
		return (NULL);
	fd = open(map, O_RDONLY);
	i = 0;
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		if (ft_strchr(map_line, '\n'))
			map_line[ft_strlen(map_line) - 1] = '\0';
		map_mat[i++] = map_line;
		map_line = get_next_line(fd);
	}
	close(fd);
	return (map_mat);
}

int	main(int argc, char *argv[])
{
	int			fd_map;
	t_mlx_win	window;

	window = (t_mlx_win){0};
	window.map = (t_mappa){0};
	window.spr = (t_sprites){0};
	fd_map = check_if_dir(&window, argc, argv);
	window.map.map_mat = get_map_matrix(argv[1], fd_map);
	window.size.y = ft_matlen(window.map.map_mat);
	window.size.x = ft_strlen(window.map.map_mat[0]);
	map_checks(&window, window.size.x, window.size.y);
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, window.size.x * IMG_WIDTH,
			window.size.y * IMG_HEIGHT, "Neo Vaporwave");
	init_sprites(&window);
	render_and_place(&window);
	mlx_hook(window.mlx_win, DestroyNotify, StructureNotifyMask, ez_exit,
		&window);
	mlx_hook(window.mlx_win, KeyPress, KeyPressMask, &key_event, &window);
	mlx_loop(window.mlx);
	return (0);
}
