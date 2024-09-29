/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:18 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 10:39:31 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	is_all_number(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

void	count_rgb(char *rgb, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error(map, 7);
}

void	parse_rgb_values(char **tmp, t_color *color, t_map *map)
{
	if (is_all_number(tmp[0]) == false)
		ft_error(map, 6);
	color->r = ft_atoi(tmp[0]);
	if (is_all_number(tmp[1]) == false)
		ft_error(map, 6);
	color->g = ft_atoi(tmp[1]);
	if (is_all_number(tmp[2]) == false)
		ft_error(map, 6);
	color->b = ft_atoi(tmp[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		ft_error(map, 6);
}

char	**get_rgb_components(char *rgb, t_map *map)
{
	char	*new_line;
	char	**tmp;
	int		i;

	i = 0;
	new_line = remove_new_line(rgb);
	count_rgb(new_line, map);
	tmp = ft_split(new_line + 1, ',');
	is_not_empty(tmp, map);
	while (tmp[i] != NULL)
		i++;
	if (i != 3)
		ft_error(map, 7);
	free(new_line);
	return (tmp);
}

void	get_rgb_value(char *rgb, t_map *map, char R)
{
	char	**tmp;

	tmp = get_rgb_components(rgb, map);
	if (R == 'F')
		parse_rgb_values(tmp, &map->floor, map);
	else if (R == 'C')
		parse_rgb_values(tmp, &map->ceiling, map);
	free_array(tmp);
}
