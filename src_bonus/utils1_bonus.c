/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:51:05 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 14:54:58 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_window	*data_grep(t_window *data)
{
	static t_window	*_data;

	if (data != NULL)
		_data = data;
	return (_data);
}

static void	free_sprint2(t_window *window)
{
	int	i;

	i = 0;
	if (window->sprite->axe)
	{
		while (i < 6)
		{
			mlx_delete_texture(window->sprite->axe[i]);
			mlx_delete_image(window->mlx_con, window->sprite->axe_images[i]);
			i++;
		}
		free(window->sprite->axe);
		free(window->sprite->axe_images);
	}
	if (window->sprite->hand)
	{
		mlx_delete_texture(window->sprite->hand);
		mlx_delete_image(window->mlx_con, window->sprite->hand_image);
	}
	free(window->sprite);
}

static void	free_sprite(t_window *window)
{
	int	i;

	i = 0;
	if (window->sprite->sword)
	{
		while (i < 6)
		{
			mlx_delete_texture(window->sprite->sword[i]);
			mlx_delete_image(window->mlx_con, window->sprite->sword_i[i]);
			i++;
		}
		(free(window->sprite->sword), free(window->sprite->sword_i));
	}
	i = 0;
	if (window->sprite->pickaxe)
	{
		while (i < 8)
		{
			mlx_delete_texture(window->sprite->pickaxe[i]);
			mlx_delete_image(window->mlx_con, window->sprite->pickaxe_i[i]);
			i++;
		}
		(free(window->sprite->pickaxe), free(window->sprite->pickaxe_i));
	}
	free_sprint2(window);
}

static void	free_texture(t_window *window)
{
	int	i;

	i = 0;
	while (i < 5)
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
	if (window->sprite)
		free_sprite(window);
	return ;
}
