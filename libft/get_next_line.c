/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:38 by moel-fat          #+#    #+#             */
/*   Updated: 2024/07/17 08:31:40 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*cnl(char **save, char *buffer, char *newline_pos)
{
	char	*temp;
	char	*line;

	temp = NULL;
	line = NULL;
	line = ft_strndup(*save, newline_pos - *save + 1);
	if (!line)
		return (free(buffer), free(*save), *save = NULL, NULL);
	temp = ft_strdup_gnl(newline_pos + 1);
	if (!temp)
		return (free(buffer), free(line), free(*save), *save = NULL, NULL);
	free(*save);
	*save = temp;
	free(buffer);
	return (line);
}

char	*ft_return(ssize_t *count, char **save, char **line, char **buffer)
{
	if (*count < 0)
		return (free(*buffer), free(*save), *save = NULL, NULL);
	if (*save && **save)
	{
		*line = ft_strdup_gnl(*save);
		if (!*line)
			return (free(*buffer), free(*save), *save = NULL, NULL);
		return (free(*save), *save = NULL, free(*buffer), *line);
	}
	if (!*line && *count == 0)
		return (free(*save), free(*buffer), *save = NULL, *save);
	return (free(*buffer), NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(save), save = NULL, NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(save), save = NULL, NULL);
	line = NULL;
	count = 1;
	if (save && ft_strchr_gnl(save, '\n'))
		return (line = cnl(&save, buffer, ft_strchr_gnl(save, '\n')));
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		save = ft_strjoin_gnl(save, buffer);
		if (!save)
			return (free(buffer), save = NULL, NULL);
		if (ft_strchr_gnl(save, '\n'))
			return (line = cnl(&save, buffer, ft_strchr_gnl(save, '\n')));
	}
	return (ft_return(&count, &save, &line, &buffer));
}
