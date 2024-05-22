/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:53:25 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/18 20:11:19 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/* 
int     main()
{
	printf("if %c\n", ft_toupper('a'));
	printf("else %c\n", ft_toupper('B'));
	printf("else %c\n", ft_toupper('!'));
	printf("else %c\n", toupper('!'));
} */
