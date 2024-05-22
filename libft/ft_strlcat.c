/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:00:00 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//NOTES
/* 
---------------------------------------------------------------------------------
man:   The strlcat() function appends the NUL-terminated string src to the end
of dst.
	 It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the re‐
	 sult.
	 Return: the initial length of dst plus the length of src.
//i need to get to the end of dst - copy src there while dst being within size
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	unsigned int	srclen;
	unsigned int	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen < size)
		srclen += dstlen;
	else
		srclen += size;
	while (src[i] && (dstlen + 1) < size)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (srclen);
}

/* int     main()
{
	char src[] = "okane";
	char dst[50] = "di";
	printf("%zu\n", ft_strlcat(dst, src, 50));
	printf("%s\n", dst);
} */