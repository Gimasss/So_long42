/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:05:10 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The  memmove()  function copies n bytes from memory
	   area src to memory area dest.  The memory areas may
	   overlap: copying takes place as though the bytes in
	   src are first copied into a  temporary  array  that
	   does  not  overlap  src  or dest, and the bytes are
	   then copied from the temporary array to dest.
memmove handles overlapping memory correctly. 
	It first checks if the source and destination overlap, and if they do, 
	it takes appropriate action to ensure the bytes are copied correctly.
	So, if you're copying between non-overlapping memory blocks, `memcpy` 
	and `memmove` will give the same output. But if the memory blocks overlap, 
	`memmove` should be used to ensure correct results.
To recreate the `ft_memmove` function, you need to handle two main scenarios: 
	when `src` is at a lower memory address than `dest`, and when `src` 
	is at a higher memory address than `dest`. 

pseudocode:

1. Check if `dest` or `src` is NULL. If either is, return NULL. OK
2. Cast `dest` and `src` to char pointers `d` and `s` respectively. OK
3. If `s` < `d`, copy the bytes from end to start.
4. If `s` >= `d`, copy the bytes from start to end.
5. Return `dest`.

*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d == s)
		return (dest);
	if (d >= s && d <= s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return ((void *)d);
}
/* 
int	main()
{
	char src[] = "Hello you";
	char dest[50];

	ft_memmove(dest, src, 7);
	dest[9] = '\0';  // Add null for prettier output when using mem
	printf("dest: %s\n", dest);

	return 0;
 	printf("%p,\td + 4 = %p\n", dest, dest + 4);
	printf("%p\n", src);
} */