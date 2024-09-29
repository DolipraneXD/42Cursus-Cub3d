/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:12:50 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:42 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	map_init(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->v_map = NULL;
	map->floor.r = -1;
	map->floor.g = -1;
	map->floor.b = -1;
	map->ceiling.r = -1;
	map->ceiling.g = -1;
	map->ceiling.b = -1;
	map->player_dir = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->map_fd = 0;
	map->data = NULL;
	map->player_count = 0;
}

void	parse_map(t_map *map)
{
	map->so = check_texture(map->so);
	map->no = check_texture(map->no);
	map->we = check_texture(map->we);
	map->ea = check_texture(map->ea);
	if (map->so == NULL || map->no == NULL || map->we == NULL
		|| map->ea == NULL)
		ft_error(map, -1);
	if (map->floor.r == -1 || map->floor.g == -1 || map->floor.b == -1)
		ft_error(map, 11);
	if (map->ceiling.r == -1 || map->ceiling.g == -1 || map->ceiling.b == -1)
		ft_error(map, 11);
	copy_map(map);
	fill_map(map);
	if (is_surrounded_by_walls(map) == false)
		ft_error(map, 3);
	if (check_if_map_is_valid(map) == false)
		ft_error(map, 3);
	remove_x(map);
	find_player(map);
	check_doors(map);
}

void	store_map(t_map *map)
{
	char	*line;
	int		count;
	bool	map_started;

	count = 0;
	map_started = false;
	while (1)
	{
		line = get_next_line(map->map_fd);
		if (line == NULL)
			break ;
		parse_line(line, map, &map_started);
		free(line);
	}
	close(map->map_fd);
	parse_map(map);
}

void	check_read_map(char *filename, t_map *map)
{
	map->map_fd = check_map_exists(filename, map);
	store_map(map);
}
