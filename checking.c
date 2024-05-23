/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:56:39 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/23 15:26:00 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	basic_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 4 && ft_strncmp(str + (len - 4), ".ber", 4) == 0)
	{
		return (ft_putstr_fd("Extension -> Correct\n", 1), 1);
	}
	else
		return (ft_putstr_fd("Extension -> Fail\n", 2), 0);
	return (0);
}

void	floodfill(t_mlx_win *window, char **map_mat, t_coord curr)
{
	const char	pos = map_mat[curr.y][curr.x];

	if (pos == '1' || pos == 'G')
		return ;
	if (pos == 'C')
		window->map.prcdio++;
	if (pos == 'E')
		window->map.prcmdnna++;
	map_mat[curr.y][curr.x] = 'G';
	floodfill(window, map_mat, (t_coord){curr.x, curr.y - 1});
	floodfill(window, map_mat, (t_coord){curr.x, curr.y + 1});
	floodfill(window, map_mat, (t_coord){curr.x - 1, curr.y});
	floodfill(window, map_mat, (t_coord){curr.x + 1, curr.y});
}

int	ff_check(t_mlx_win *window)
{
	char	**copy;

	copy = mat_copy(window->map.map_mat, window->size.y);
	if (!copy)
		return (0);
	floodfill(window, copy, window->map.player);
	ft_free_matrix(copy);
	if (window->map.ff_exit != 1)
		return (0);
	if (window->map.collectible != window->map.ff_collect)
		return (0);
	return (1);
}

void	map_checks(t_mlx_win *window, int rows, int cols)
{
	rows = window->size.y;
	cols = window->size.x;
	if (check_lines(rows, cols, window->map.map_mat) == 0)
		ft_exit(window, "Error - What's happening with those lines\n", 13);
	if (check_elements(rows, cols, window) == 0)
		ft_exit(window, "Error - Wrong elements in map\n", 13);
	if (count_elements(rows, cols, window->map.map_mat, 'P') != 1)
		ft_exit(window, "Error - What in the Dolphin is going on?\n", 13);
	window->map.collectible = count_elements(rows, cols,
			window->map.map_mat, 'C');
	if (window->map.collectible <= 0)
		ft_exit(window, "Error - Where is the DATA?\n", 13);
	if (count_elements(rows, cols, window->map.map_mat, 'E') != 1)
		ft_exit(window, "Error - Cannot escape, \
		cannot come out...MAMAAA\n", 13);
	if (check_walls(window->map.map_mat, rows, cols) == 0)
		ft_exit(window, "Error - Breach in the walls\n", 13);
	if (!ff_check(window))
		ft_exit(window, "Error - OVERFLOODfill", 13);
}
