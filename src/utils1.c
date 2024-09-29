/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:45:14 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 10:49:49 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_window	*data_grep(t_window *data)
{
	static t_window	*_data;

	if (data != NULL)
		_data = data;
	return (_data);
}

static void	free_texture(t_window *window)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (window->texture[i])
			mlx_delete_texture(window->texture[i]);
		i++;
	}
	free(window->texture);
}

void	free_on_error(void)
{
	t_window	*window;

	window = data_grep(NULL);
	if (window->map)
		free_map(window->map);
	if (window->texture)
		free_texture(window);
	return ;
}
