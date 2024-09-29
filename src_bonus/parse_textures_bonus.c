/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:28:43 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 10:39:31 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*check_texture(char *str)
{
	char	*path;
	int		fd;

	if (str == NULL)
		return (ft_putstr_fd("Error\nMissing Texture Path\n", 2), NULL);
	path = ft_strtrim(str + 2, " \t\n");
	if ((path == NULL || *path == '\0') && (*str + 2) != ' ')
	{
		free(path);
		ft_putstr_fd("Error\nInvalid Texture path\n", 2);
		return (NULL);
	}
	free(str);
	str = path;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid Texture Path or permission denied\n", 2);
		free(path);
		return (NULL);
	}
	close(fd);
	return (str);
}
