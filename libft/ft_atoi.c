/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:23:04 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// #include <limits.h>

// int		main()
// {
// 	printf("%d\n", atoi("986"));
// 	printf("%d\n", ft_atoi("986"));

// 	printf("%d\n", atoi("--986"));
// 	printf("%d\n", ft_atoi("--986"));

// 	printf("[%d]: %d\n", INT_MAX, atoi("2147483647"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("[%d]: %d\n", INT_MIN, atoi("−2147483647"));
// 	printf("%d\n", ft_atoi("−2147483647"));

// 	printf("%d\n", atoi(" 986"));
// 	printf("%d\n", ft_atoi(" 986"));
// } 