/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:58:45 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/01 18:18:27 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* 
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	void			*boh;

	i = 0;
	boh = (void *)malloc(nmemb * size);
	if (!boh)
		return (NULL);
	res = (unsigned char *)boh;
	while (i < nmemb * size)
	{
		res[i++] = 0;
	}
	return (boh); 
}
*/

char	*ft_strjoin_free(char *s1, char *s2)
{
	int				i;
	char			*cat;
	char			*sc1;
	char			*sc2;

	i = 0;
	sc1 = s1;
	sc2 = s2;
	cat = ft_calloc((ft_strlen(sc1) + ft_strlen(sc2) + 1), sizeof(char));
	if (!cat)
		return (NULL);
	while (*sc1)
	{
		cat[i] = *sc1;
		i++;
		sc1++;
	}
	while (*sc2)
	{
		cat[i] = *sc2;
		i++;
		sc2++;
	}
	free (s1);
	return (cat);
}
/* 
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
} */
