/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:29:24 by mal-mora          #+#    #+#             */
/*   Updated: 2024/09/26 14:41:52 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_correct_distance(t_window *window, int i)
{
	window->ray_list[i].distance *= cos(window->ray_list[i].ray_angle \
		- window->player.rotation_angle);
}

double	calculate_wall_top_pixel(double wall_strip_height)
{
	double	wall_top_pixel;

	wall_top_pixel = (HEIGHT / 2) - (wall_strip_height / 2);
	return (wall_top_pixel);
}

double	calculate_wall_bottom_pixel(double wall_strip_height)
{
	double	wall_bottom_pixel;

	wall_bottom_pixel = (HEIGHT / 2) + (wall_strip_height / 2);
	return (wall_bottom_pixel);
}
