/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:01 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/26 17:32:08 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ez_exit(t_mlx_win *win)
{
	free_exit(win, 0);
	return (0);
}

void	ft_free_matrix(char **map_mat)//CLEAN FILE
{
	int	i;

	i = 0;
	if (map_mat == NULL)
		return ;
	while (map_mat[i] != NULL)
	{
		free(map_mat[i]);
		i++;
	}
	free(map_mat);
}

int	ft_exit(t_mlx_win *window, char *str, int flag)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd("Bye", 2);
	if (window)
		free_exit(window, flag);
	exit(flag);
}

void	free_sprites(t_mlx_win *window)
{
	if (window->spr.wall)
		mlx_destroy_image(window->mlx, window->spr.wall);
	if (window->spr.floor)
		mlx_destroy_image(window->mlx, window->spr.floor);
	if (window->spr.player)
		mlx_destroy_image(window->mlx, window->spr.player);
	if (window->spr.collectible)
		mlx_destroy_image(window->mlx, window->spr.collectible);
	if (window->spr.enemy)
		mlx_destroy_image(window->mlx, window->spr.enemy);
	if (window->spr.exit)
		mlx_destroy_image(window->mlx, window->spr.exit);
	if (window->spr.exit_2)
		mlx_destroy_image(window->mlx, window->spr.exit_2);
}

int	free_exit(t_mlx_win *window, int flag)
{
	ft_free_matrix(window->map.map_mat);
	free_sprites(window);
	if (window->mlx)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	ft_putstr_fd("Bye", 1);
	exit(flag);
}
