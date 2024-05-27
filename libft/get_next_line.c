/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:01:01 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/27 13:46:15 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "includes/libft.h"

char	*ft_leftover_file(char *selection, char *line)
{
	size_t	i;
	size_t	j;
	size_t	snippet;

	i = 0;
	j = 0;
	while (selection[i] && selection[i] != '\n')
		i++;
	if (!selection[i])
	{
		free(selection);
		return (NULL);
	}
	snippet = ft_strlen(selection) - i;
	line = ft_calloc(snippet + 1, sizeof(char));
	i++;
	while (selection[i])
		line[j++] = selection[i++];
	free(selection);
	return (line);
}

char	*ft_defined_line(char *selection)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!selection[i])
		return (NULL);
	while (selection[i] && selection[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (selection[i] && selection[i] != '\n')
		line[j++] = selection[i++];
	if (selection[i] == '\n')
		line[j] = '\n';
	return (line);
}

char	*ft_read(int fd, char *selection)
{
	ssize_t	bytes_read;
	char	*read_sel;

	if (!selection)
		selection = ft_calloc(1, sizeof(char));
	read_sel = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (!ft_strchr(selection, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_sel, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (read_sel);
			free (selection);
			return (NULL);
		}
		read_sel[bytes_read] = '\0';
		selection = ft_strjoin_free(selection, read_sel);
	}
	free (read_sel);
	return (selection);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*page;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	page = ft_read(fd, page);
	if (!page)
		return (NULL);
	line = ft_defined_line(page);
	page = ft_leftover_file(page, line);
	return (line);
}
/* 
int main(int argc, char *argv[])
{
	char	*line;
	int		fd = open(argv[1], O_RDONLY);

	if (!argc)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */