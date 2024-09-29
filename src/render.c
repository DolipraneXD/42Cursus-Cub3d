/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:18:28 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 11:00:25 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_floor_ceiling(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(window->img, x, y, window->floor_color);
			else
				mlx_put_pixel(window->img, x, y, window->ceiling_color);
			x++;
		}
		y++;
	}
}

void	render(t_window *window)
{
	draw_floor_ceiling(window);
	rays_casting(window);
	render_walls(window);
}
