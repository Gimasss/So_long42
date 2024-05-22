/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:08:01 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//NOTES 
/* 
FUNCTION returns a pointer to the first occurrence of the character c 
	in the string s.
RETURN a  pointer  to  the matched  character  or  NULL  if the character 
is not found.  The terminating null byte is considered part of the string,  
so  that if  c  is  specified as '\0', these functions return a pointer to
the terminator 
(x) controllo sugli ascii - se mi viene passato un valore maggiore alla tabella,
mi fa modulo del carattere passato cosi' da ritrovarmelo nella tabella
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 127)
		c = c % 128;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
/* 
int main()
{
	char s[] = "poppante";
	int c = 'a';
	char *test;
	test = ft_strchr(s, c);
	write (1, &test, 6);
	write (1, "\n", 1); 
   printf("%s\n", strchr(s, c));
}
*/