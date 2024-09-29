/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:47:09 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 11:31:04 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		free_on_error();
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

char	*remove_new_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_strndup(str, i);
	free(str);
	return (tmp);
}

bool	is_just_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void	is_not_empty(char **line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (is_just_spaces(line[i]) == true)
			ft_print_error(map, "Empty RGB value", -1);
		i++;
	}
}

void	remove_x(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->v_map[i][j] == 'x')
				map->v_map[i][j] = '0';
			j++;
		}
		i++;
	}
}
