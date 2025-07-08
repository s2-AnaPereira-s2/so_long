/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:19:32 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/08 08:54:33 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_leftovers(char **leftovers)
{
	int		i;
	char	*line;
	char	*temp;
	int		length;

	if (!*leftovers)
		return (NULL);
	length = ft_strlen(*leftovers);
	i = 0;
	while ((*leftovers)[i])
	{
		if ((*leftovers)[i] == '\n')
		{
			line = ft_substr(*leftovers, 0, i + 1);
			temp = ft_substr(*leftovers, i + 1, length - (i + 1));
			if (!temp)
				return (free(line), NULL);
			free(*leftovers);
			*leftovers = temp;
			return (line);
		}
		i++;
	}
	return (NULL);
}

static char	*get_line(char	**leftovers, char	*temp, ssize_t bytes)
{
	char	*line;
	char	*joined;

	temp[bytes] = '\0';
	if (!*leftovers)
		*leftovers = ft_strdup("");
	joined = ft_strjoin(*leftovers, temp);
	if (!joined)
		return (free(temp), NULL);
	*leftovers = joined;
	line = check_leftovers(leftovers);
	if (line)
		return (free(temp), line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*leftovers;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(leftovers), leftovers = NULL, NULL);
	line = check_leftovers(&leftovers);
	if (line)
		return (line);
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (free(leftovers), leftovers = NULL, NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	while (bytes > 0)
	{
		line = get_line(&leftovers, temp, bytes);
		if (line)
			return (line);
		bytes = read(fd, temp, BUFFER_SIZE);
	}
	if (bytes == -1 || !leftovers || *leftovers == '\0')
		return (free(temp), free(leftovers), leftovers = NULL, NULL);
	return (free(temp), line = leftovers, leftovers = NULL, line);
}
