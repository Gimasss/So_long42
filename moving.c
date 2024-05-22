/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:17:36 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/22 20:11:51 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int ft_yesorno(char **map, t_coord pos)
{
	if (map[pos.y][pos.x] == '1')
		return (0);
	return (1);
}

int strolling_around(t_mlx_win *window, t_coord pos)
{
	char **map;
	map = window->map.map_mat;
	if (ft_yesorno(map, pos) == 0)
		return (0);
	//ora possiamo sicuramente spostarci. baubau

	if (map[pos.y][pos.x] == COLLECTIBLE)
		window->map.collectible--;
	if (map[pos.y][pos.x] == ENEMY)
		ft_exit(window, "YOU'VE TURNED INTO a STONER\n", 0);
	if (window->map.exit.x == pos.x && window->map.exit.y == pos.y
		&& window->map.collectible == 0)
		ft_exit(window, "YOU MADE IT OUT OF THE MATRIX, NEO\n", 0);
	map[window->map.player.y][window->map.player.x] = FLOOR;//1 put floor where player was
	map[window->map.exit.y][window->map.exit.x] = EXIT;//2 where exit is i put exit back, before player to avoid comprmising exit
	map[pos.y][pos.x] = PLAYER;
	window->map.player = pos;//updating player position before rendering
	render_and_place(window);
	window->moves++;
	ft_printf("Splash count: %d\n", window->moves);
	return (1);
}
int	key_event(int key, t_mlx_win *window)
{
	int	x;
	int	y;

	if (key == ESC)
			ft_exit(window, "YOU ESCAPED THE MATRIX\n", 0);

	x = window->map.player.x;
	y = window->map.player.y;

	if (key == UP)
		strolling_around(window, (t_coord){x, y - 1});
	if (key == DOWN)
		strolling_around(window, (t_coord){x, y + 1});
	if (key == LEFT)
		strolling_around(window, (t_coord){x - 1, y});
	if (key == RIGHT)
		strolling_around(window, (t_coord){x + 1, y});
	return (0);
}
