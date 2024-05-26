/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:24:11 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/23 16:07:38 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*convert_image(t_mlx_win *window, char *c, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(window->mlx, c, &x, &y);
	return (img);
}

void	upload_image(t_mlx_win *window, void *c, int x, int y)
{
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		c, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	upload_exit(t_mlx_win *window, int i, int j)
{
	if (window->map.map_mat[j][i] != 'E')
		return ;
	upload_image(window, window->spr.exit, i, j);
	if (window->map.collectible == 0)
		upload_image(window, window->spr.exit_2, i, j);
}

int	render_and_place(t_mlx_win *window)
{
	int		i;
	int		j;
	char	c;

	j = -1;
	while (++j < window->size.y)
	{
		i = -1;
		while (++i < window->size.x)
		{
			c = window->map.map_mat[j][i];
			if (c == '0')
				upload_image(window, window->spr.floor, i, j);
			else if (c == '1')
				upload_image(window, window->spr.wall, i, j);
			else if (c == 'P')
				upload_image(window, window->spr.player, i, j);
			else if (c == 'C')
				upload_image(window, window->spr.collectible, i, j);
			else if (c == 'N')
				upload_image(window, window->spr.enemy, i, j);
			upload_exit(window, i, j);
		}
	}
	return (0);
}
