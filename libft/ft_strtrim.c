/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:49 by gmastroc          #+#    #+#             */
/*   Updated: 2023/12/19 17:43:03 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters --> s1: The string to be trimmed. -->set: The reference set of 
characters to trim.
Return value --> The trimmed string. NULL if the allocation fails.
Description --> Allocates (with malloc(3)) and returns a copy of ’s1’ 
with the characters specified in ’set’ removed from the beginning and 
the end of the string. */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		len;
	char	*s1cpy;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, (int)s1[i]))
	{
		i++;
	}
	while (i < len && ft_strchr(set, (int)s1[len - 1]))
	{
		len--;
	}
	s1cpy = malloc(sizeof(char) * (len - i + 1));
	if (!s1cpy)
		return (NULL);
	while (i < len)
	{
		s1cpy[j++] = s1[i++];
	}
	s1cpy[j] = '\0';
	return (s1cpy);
}
/* #include <string.h>

int	main(void)
{
	char s1[] = "poll\netto";
	char set[] = "p\no";

	char s1[] = "polletto";
	char set[] = "po";

	char s1[] = "polletto";
	char set[] = " ";

	printf("%s\n", ft_strtrim(s1, set));
} */