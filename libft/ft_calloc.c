/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:07:14 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
	The calloc() function allocates memory for  an  array
	   of  nmemb  elements  of size bytes each and returns a
	   pointer to the allocated memory.  The memory  is  set
	   to  zero.   If  nmemb/size = 0, calloc() re‐
	   turns NULL/pointer value to be passed to free().
	   If nmemb * size = int overflow, returns an error.  
	   By contrast, an integer overflow would not be  detected  in
	   the  following call to malloc(), with the result that
	   an incorrectly sized block of memory would  be  allo‐
	   cated:
malloc(nmemb * size); 
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (nmemb * size));
	return (res);
}
/* while (i < (nmemb * size))
	{
		call[i] = '\0';
		i++;
	} */
/* 
int main()
{
	char *s = ft_calloc(2, sizeof(char));
	s[0] = 'a';
	printf("%s\n", s);
	free(s);
} */