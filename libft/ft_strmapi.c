/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:21:54 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/19 15:44:32 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Parameters s: The string on which to iterate.f: The function to apply to each 
character.
Return value The string created from the successive applications of ’f’. 
Returns NULL if the allocation fails.
Description Applies the function ’f’ to each character of the string ’s’, and 
passing its index as first argument to create a new string (with malloc(3)) 
resulting from successive applications of ’f’.
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
/* 
char 	toup(unsigned int i, char c)
{
	c -= 32;
	return c;
}

int 	main()
{
	char s[] = "bombastic";
	char *str;

	str = ft_strmapi(s, toup);
	printf("%c\n", str[1]);
	
}  */