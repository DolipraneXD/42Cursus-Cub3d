/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:18:08 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 13:27:36 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_deriction(t_map *map, char c)
{
	if (c == 'N')
		map->player_dir = NORTH;
	else if (c == 'E')
		map->player_dir = EAST;
	else if (c == 'S')
		map->player_dir = SOUTH;
	else if (c == 'W')
		map->player_dir = WEST;
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->v_map[y] != NULL)
	{
		x = 0;
		while (map->v_map[y][x] != '\0')
		{
			if (map->v_map[y][x] == 'N' || map->v_map[y][x] == 'S'
				|| map->v_map[y][x] == 'E' || map->v_map[y][x] == 'W')
			{
				check_deriction(map, map->v_map[y][x]);
				map->player_x = x;
				map->player_y = y;
				map->player_count++;
			}
			x++;
		}
		y++;
	}
	if (map->player_x == -1 || map->player_y == -1 || map->player_dir == -1)
		ft_error(map, 8);
	if (map->player_count != 1)
		ft_print_error(map, "There should be only one player", -1);
}
