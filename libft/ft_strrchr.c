/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:08:23 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/18 20:10:37 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTES
/*
The strrchr() function returns a pointer to the  last  occurrence
of the character c in the string s.
Return  a  pointer  to  the matched  character  or  NULL  if 
the character is not found.
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c > 127)
		c = c % 128;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/* 
int main()
{
	char s[] = "laido";
	int c = 'a';
	printf("%s\n", ft_strrchr(s, c));
	write (1, &test, 6);
	write (1, "\n", 1);  
} */
