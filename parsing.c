/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:05:30 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/23 15:54:30 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_if_dir(t_mlx_win *window, int argc, char *argv[])
{
	int		fd_map;

	if (argc != 2)
		ft_exit(window, "Error - What are you doing babe\n", 1);
	if (basic_check(argv[1]) == 0)
		ft_exit(window, "Error - Wrong extension\n", 2);
	fd_map = open(argv[1], O_DIRECTORY);
	if (fd_map > 0)
	{
		close(fd_map);
		ft_exit(window, "Error - It's a directory\n", 3);
	}
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map < 0)
		ft_exit(window, "Error - Can't open file\n", 4);
	return (fd_map);
}

int	check_lines(int rows, int cols, char **map_mat)//2
{
	int	i;
	int	row_len;

	i = 0;
	if (rows <= 3 || cols <= 3)
	{
		return (ft_printf("Map too small, wrong vibes\n", 2), 0);
	}
	while (i < rows)
	{
		row_len = ft_strlen(map_mat[i]);
		if (cols != row_len)
		{
			return (ft_printf("different lines, wrong vibes\n", 2), 0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map_mat, int rows, int cols)
{
	int	i;
	int	j;
	int	last_col;

	i = 0;
	last_col = cols - 1;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == last_col)
			{
				if (map_mat[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(int rows, int cols, char **map, char to_check)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == to_check)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	check_elements(int rows, int cols, t_mlx_win *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map.map_mat;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P'
			&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N')
				return (0);
			if (map[i][j] == 'P')
				game->map.player = (t_coord){j, i};
			if (map[i][j] == 'E')
				game->map.exit = (t_coord){j, i};
		}
	}
	return (1);
}
