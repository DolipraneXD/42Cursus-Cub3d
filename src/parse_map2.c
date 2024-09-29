/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:48:10 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 11:04:50 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_top_bottom_walls(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (map->v_map[0][j] != '1' && map->v_map[0][j] != 'x')
			return (false);
		if (map->v_map[map->height - 1][j] != '1'
			&& map->v_map[map->height - 1][j] != 'x')
			return (false);
		j++;
	}
	return (true);
}

bool	check_left_right_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->v_map[i][0] != '1' && map->v_map[i][0] != 'x')
			return (false);
		if (map->v_map[i][map->width - 1] != '1'
			&& map->v_map[i][map->width - 1] != 'x')
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_map_characters(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->v_map[i][j];
			if (c != '1' && c != '0' && c != 'x' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_surrounded_by_walls(t_map *map)
{
	if (!check_top_bottom_walls(map))
		return (false);
	if (!check_left_right_walls(map))
		return (false);
	if (!check_valid_map_characters(map))
		return (false);
	return (true);
}
