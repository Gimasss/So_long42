/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:49:44 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/18 20:41:31 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTES
/* 
The strnstr() function locates the first occurrence of the null-terminated 
	string little in the string big, where not more than len
	characters are searched.
If little is an empty string, big is returned; if little occurs nowhere in
	big, NULL is returned; otherwise a pointer to the first character of 
	the first occurrence of little is returned.

	ritorno un puntatore di big
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && big[i + j] && little[j])
			j++;
		if (little[j] == 0 && j + i <= len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/* 
int main(int argc, char* argv[])
{
	if (argc == 3)
		printf("%s\n", ft_strnstr(argv[1], argv[2], 11));
	   //(ft_strnstr(argv[1], argv[2], 11));
	return 0;
} */