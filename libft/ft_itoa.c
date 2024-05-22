/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:02:10 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	long	n;
	int		len;

	len = nbrlen(nbr);
	n = nbr;
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	len--;
	if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (len >= 0 +(nbr < 0))
	{
		res[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (res);
}
/*  
int main()
{
	printf("%s\n", ft_itoa(-663253));
	printf("%s\n", ft_itoa(663253));
}
*/