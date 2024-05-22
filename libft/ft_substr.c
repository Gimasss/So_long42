/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:06:00 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/19 15:11:53 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
return The substring.
NULL if the allocation fails.
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
 */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			s_len;
	size_t			sub_len;
	unsigned char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	sub = ft_calloc((sub_len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return ((char *)sub);
}

/* 
alternativa:
malloc ---> 
ft_strlcpy(sub_len(dest), s + start (stringa in pos start), sub_len + 1)
no need for calloc as I null terminate by giving the size in cpy.
*/
/* 
int main()
{
	char s[] = "polletto arrosto";
	char *c;
	c = ft_substr(s, 20, 1);
	printf("%s\n", c);
	free(c);
} */