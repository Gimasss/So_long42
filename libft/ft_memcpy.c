/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:35:12 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The `memcpy` and `memmove` functions in C both copy `n` bytes from the source
(`src`) to the destination (`dest`), but they behave differently when the source
and destination blocks overlap.
memcpy does not handle overlapping memory correctly. If the source and 
	destination overlap, the behavior of `memcpy` is undefined. 
	It may result in unexpected output or even program crashes.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	return (ft_memmove (dest, src, n));
}

/*
{
	size_t i;
	char *d;
	char *s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;

	if (!dest && !src)
		return (NULL);

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
} 

int main()
{
	char dest[] = "bohhhhhhhhhh";
	char src[] = "immane";
	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);
	return 0;
}
*/