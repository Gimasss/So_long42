/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiliting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:55:32 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/23 16:11:13 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <bits/fcntl-linux.h>

void	ft_print_matrix(char **map_mat)
{
	int	i;

	i = 0;
	while (map_mat[i] != NULL)
	{
		ft_printf("%s\n", map_mat[i]);
		i++;
	}
}

int	ft_matlen(char **map_mat)
{
	int	i;

	i = 0;
	while (map_mat[i] != NULL)
	{
		i++;
	}
	return (i);
}

char	**mat_copy(char **mat, int rows)
{
	char	**res;
	int		i;

	res = ft_calloc(rows + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		res[i] = ft_strdup(mat[i]);
		if (!res[i])
			return (ft_free_matrix(res), NULL);
	}
	return (res);
}
