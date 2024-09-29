/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:34:45 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 14:47:44 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copy_map_data(t_map *map, t_data *current)
{
	int		i;
	char	*tmp;

	i = 0;
	while (current != NULL)
	{
		if (current->data[0] == '\n')
		{
			map->map[i] = NULL;
			ft_error(map, 5);
		}
		tmp = remove_new_line(ft_strdup(current->data));
		if (is_just_spaces(tmp) == true)
		{
			map->map[i] = NULL;
			free(tmp);
			ft_error(map, 5);
		}
		map->map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
		current = current->next;
	}
	map->map[i] = NULL;
}

void	copy_map(t_map *map)
{
	t_data	*current;

	current = map->data;
	while (current != NULL && is_just_spaces(current->data) == true)
	{
		map->height--;
		current = current->next;
	}
	map->map = safe_malloc(sizeof(char *) * (map->height + 1));
	copy_map_data(map, current);
}

int	check_map_exists(char *file_name, t_map *map)
{
	int	fd;
	int	len;

	len = ft_strlen(file_name);
	if ((len < 4) || ft_strnstr(&file_name[len - 4], ".cub", len) == NULL)
		ft_error(map, 2);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error(map, 2);
	return (fd);
}

void	parse_line_helper(char *line, t_map *map, bool *map_started, char *tmp)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0 && map->no == NULL)
		map->no = ft_strdup(tmp);
	else if (ft_strncmp(tmp, "SO ", 3) == 0 && map->so == NULL)
		map->so = ft_strdup(tmp);
	else if (ft_strncmp(tmp, "WE ", 3) == 0 && map->we == NULL)
		map->we = ft_strdup(tmp);
	else if (ft_strncmp(tmp, "EA ", 3) == 0 && map->ea == NULL)
		map->ea = ft_strdup(tmp);
	else if (ft_strncmp(tmp, "F ", 2) == 0 && map->floor.r == -1)
		get_rgb_value(ft_strdup(tmp), map, 'F');
	else if (ft_strncmp(tmp, "C ", 2) == 0 && map->ceiling.r == -1)
		get_rgb_value(ft_strdup(tmp), map, 'C');
	else if (ft_strncmp(tmp, "1", 1) == 0)
	{
		*map_started = true;
		map->height++;
		ft_lstadd_backmap(&map->data, ft_lstnewmap(ft_strdup(line)));
	}
	else if (tmp[0] != '\n')
		ft_error(map, 4);
}

void	parse_line(char *line, t_map *map, bool *map_started)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (!(*map_started))
	{
		parse_line_helper(line, map, map_started, tmp);
	}
	else
	{
		if (ft_strncmp(tmp, "1", 1) == 0 || tmp[0] == '\n')
		{
			map->height++;
			ft_lstadd_backmap(&map->data, ft_lstnewmap(ft_strdup(line)));
		}
		else if (tmp[0] != '\n')
			ft_error(map, 5);
	}
	free(tmp);
}
