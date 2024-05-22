/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:09:03 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/18 20:07:51 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

//casting to int saves me from possible probs
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
/* 
int main()
{
	char *s1 = "''''";
	printf("%d\n", ft_strncmp(s1, "bia", 99));
	printf("%d\n", strncmp(s1, "bia", 99));
	printf("%d\n", ft_strncmp("madre", "MADRE", 5));
	printf("%d\n", strncmp("madre", "MADRE", 5));
} */