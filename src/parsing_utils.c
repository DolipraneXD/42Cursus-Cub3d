/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:22:48 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 10:25:55 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_map(t_map *map)
{
	t_data	*current;
	t_data	*next;

	if (map == NULL)
		return ;
	current = map->data;
	while (current != NULL)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	if (map != NULL)
		free_array(map->map);
	free_array(map->v_map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free(map);
}

void	ft_error(t_map *map, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Error\nNeed The Map path as second arg and no more", 2);
	else if (flag == 2)
		ft_putstr_fd("Error\nNo Map Exists OR Invalid File Extension", 2);
	else if (flag == 3)
		ft_putstr_fd("Error\nNot closed by walls or have extra elemnet", 2);
	else if (flag == 4)
		ft_putstr_fd("Error\nunwanted elemnet in the file or duplicate", 2);
	else if (flag == 5)
		ft_putstr_fd("Error\nfound emptyline or unwanted element in map", 2);
	else if (flag == 6)
		ft_putstr_fd("Error\nInvalid RGB between 0 and 255 with no spaces", 2);
	else if (flag == 7)
		ft_putstr_fd("Error\nInvalid arguments for RGB format", 2);
	else if (flag == 8)
		ft_putstr_fd("Error\nplayer not found or wrong dericetion", 2);
	else if (flag == 9)
		ft_putstr_fd("Error\nmalloc fail\n", 2);
	else if (flag == 10)
		ft_putstr_fd("Error\nInvalid Texture Path or permition \n", 2);
	else if (flag == 11)
		ft_putstr_fd("Error\nColors are missing or missmatch\n", 2);
	if (map != NULL)
		free_map(map);
	exit(EXIT_FAILURE);
}

void	ft_print_error(t_map *map, char *str, int flag)
{
	ft_putstr_fd("Error\n", 2);
	if (str != NULL && flag == -1)
		ft_putstr_fd(str, 2);
	ft_error(map, flag);
}
