/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:24:11 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/22 20:09:54 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <so_long.h>

void	*convert_image(t_mlx_win *window, char *c, int x, int y) //loads the xpm.img and renders it
{
	void *img;
	img = mlx_xpm_file_to_image(window->mlx, c, &x, &y);
	// ft_printf("image loaded\n");
	return (img);
}
void upload_image(t_mlx_win *window, void *c, int x, int y)
{
	// ft_printf("in position %d %d there is a %c\n", x, y, window->map.map_mat[y][x]);
	mlx_put_image_to_window(window->mlx, window->mlx_win, 
	c, x * IMG_WIDTH, y * IMG_HEIGHT);
	// printf("image uploaded\n");
}

int	render_and_place(t_mlx_win *window)
{
	int i;
	int	j;
	char c;

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
				upload_image(window,  window->spr.wall, i, j);
			else if (c == 'P')
				upload_image(window,  window->spr.player, i, j);
			else if (c == 'C')
				upload_image(window,  window->spr.collectible, i, j);
			else if (c == 'N')
				upload_image(window,  window->spr.enemy, i, j);
			else if (c == 'E')
			{
				upload_image(window,  window->spr.exit, i, j);
				if (window->map.collectible == 0)
						upload_image(window,  window->spr.exit_2, i, j);
			}
		}
	}
	return (0);
}
