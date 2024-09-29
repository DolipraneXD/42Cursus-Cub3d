/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:18:36 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/21 17:43:47 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	get_wall_height(t_window *window, int i)
{
	double	distance_proj_plane;
	double	wall_strip_height;

	distance_proj_plane = (WIDTH / 2) / tan(window->fov_angle / 2);
	if (window->ray_list[i].distance == 0)
		window->ray_list[i].distance = 1;
	wall_strip_height = (TILE_SIZE / window->ray_list[i].distance)
		* distance_proj_plane;
	return (wall_strip_height);
}

uint32_t	convert_color(t_color *color)
{
	return ((uint32_t)color->r << 24 | (uint32_t)color->g << 16
		| (uint32_t)color->b << 8 | 255);
}

double	calc_distance(double X0, double Y0, double X, double Y)
{
	return (sqrt((X - X0) * (X - X0) + (Y - Y0) * (Y - Y0)));
}

uint32_t	ft_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | (uint32_t)a);
}

uint32_t	get_pixel_color(mlx_texture_t *texture, uint32_t x, uint32_t y)
{
	int			index;
	uint32_t	color;

	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		index = (y * texture->width + x) * texture->bytes_per_pixel;
		color = ft_rgba(texture->pixels[index], texture->pixels[index + 1],
				texture->pixels[index + 2], texture->pixels[index + 3]);
	}
	else
		color = ft_rgba(0, 0, 0, 255);
	return (color);
}
