/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:00:07 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTES
/* With the strlcpy() function, however, only dstsize characters maximum are 
copied, and the value returned is the size of string src. 
(The value returned is always the size of string src regardless of how many 
characters are copied.)
----------------------------------------------------------------------------
man:   The strlcpy() function copies up to size - 1 characters from the 
NUL-terminated string src to dst, NUL-terminating the result.
	 Returns the total length of the string it tried to create.  
	 That means the length of src(11 + null?).
 */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/* int     main()
{
	char dst[10];
	char src[11] = "hey bitches";
	printf("I copied: %d\n", ft_strlcpy(dst, src, 10));
	//printf("I copied: %d\n", strlcpy(dst, src, 9));
	printf("I copied: %s\n", dst);
} */