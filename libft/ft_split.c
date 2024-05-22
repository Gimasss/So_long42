/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:52:43 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters s: The string to be split. c: The delimiter character.
Return value The array of new strings resulting from the split. 
NULL if the allocation fails.
Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer. 
*/

#include "libft.h"

static	size_t	ft_lim(char s, char c)
{
	if (s == c || s == 0)
		return (1);
	return (0);
}

static size_t	ft_wordcount(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_lim(*s, c) == 1)
			s++;
		if (*s && ft_lim(*s, c) == 0)
		{
			count++;
			while (*s && ft_lim(*s, c) == 0)
				s++;
		}
	}
	return (count);
}

static	char	*ft_wdmall(char *s, char c)
{
	size_t	i;
	char	*wd;

	i = 0;
	while (s[i] && ft_lim(s[i], c) == 0)
		i++;
	wd = ft_calloc(sizeof(char), (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (s[i] && ft_lim(s[i], c) == 0)
	{
		wd[i] = s[i];
		i++;
	}
	return (wd);
}

static void	ft_free(char **res, int i)
{
	i--;
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
}

char	**ft_split(const char *s, char c)
{
	char			**res;
	size_t			i;

	res = ft_calloc(sizeof(char *), (ft_wordcount((char *)s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_lim(*s, c) == 1)
			s++;
		if (*s && ft_lim(*s, c) == 0)
		{
			res[i] = ft_wdmall((char *)s, c);
			if (!res[i])
			{
				ft_free(res, i);
				return (NULL);
			}
			i++;
			while (*s && ft_lim(*s, c) == 0)
				s++;
		}
	}
	return (res);
}

/* int	main(void)
{
	char	**split;
	char	*s = "dammi una lametta";
	int		i;
	split = ft_split(s, ' ');

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	printf("<%s>\n", split[i]);
} */