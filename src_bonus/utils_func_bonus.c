/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:27:05 by mal-mora          #+#    #+#             */
/*   Updated: 2024/09/26 11:39:39 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	check_hits(t_window *window, int x_new, int y_new, int is_hits)
{
	if (is_hits)
		return ((window->map->v_map[y_new / TILE_SIZE][x_new / \
			TILE_SIZE] == '1' || window->map->v_map[(y_new / \
				TILE_SIZE)][x_new / TILE_SIZE] == 'D'));
	else
		return ((window->map->v_map[y_new / TILE_SIZE][(x_new) / \
			TILE_SIZE] != '1') && (window->map->v_map[(y_new) / \
				TILE_SIZE][(x_new) / TILE_SIZE] != 'D'));
	return (false);
}

bool	ray_protection(t_ray_cast ray_var, t_window *window)
{
	return (ray_var.xinter >= 0 && ray_var.xinter <= window->width && \
		ray_var.yinter >= 0 && ray_var.yinter <= window->height);
}

void	init_helper(t_window *window)
{
	window->sprite->sword = NULL;
	window->sprite->sword_i = NULL;
	window->sprite->pickaxe = NULL;
	window->sprite->pickaxe_i = NULL;
	window->sprite->axe = NULL;
	window->sprite->axe_images = NULL;
	window->sprite->hand = NULL;
	window->sprite->hand_image = NULL;
	window->sprite->current_animation_images = NULL;
	window->sprite->whatison = 0;
	window->sprite->num_frames = 0;
	window->sprite->num_frames_set = false;
	window->sprite->hand_on = false;
	window->sprite->enabled = false;
}
