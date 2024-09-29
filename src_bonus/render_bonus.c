/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:18:28 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 10:39:31 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

void	draw_player(t_window *window)
{
	int	x;
	int	y;

	y = MINIMAP_WIDTH / 2;
	while (y < (MINIMAP_WIDTH / 2) + PLAYER_SIZE)
	{
		x = MINIMAP_HEIGHT / 2;
		while (x < (MINIMAP_HEIGHT / 2) + PLAYER_SIZE)
		{
			if ((x - PLAYER_PIX_CENTER) * (x - PLAYER_PIX_CENTER) + \
				(y - PLAYER_PIX_CENTER) * (y - PLAYER_PIX_CENTER) < \
					(PLAYER_SIZE / 2) * (PLAYER_SIZE / 2))
				mlx_put_pixel(window->img, x, y, RED);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_window *window, t_render_vars *re_vars, int x, int y)
{
	if (re_vars->map_y >= 0 && re_vars->map_x >= 0 && \
		re_vars->map_y < window->map->height && \
			re_vars->map_x < window->map->width)
	{
		if (window->map->v_map[re_vars->map_y][(re_vars->map_x)] == '1')
			mlx_put_pixel(window->img, x, y, BLACK);
		else if (window->map->v_map[re_vars->map_y][(re_vars->map_x)] == 'D')
			mlx_put_pixel(window->img, x, y, BROWN);
		else
			mlx_put_pixel(window->img, x, y, 0xFFFFFFFF);
	}
	else
		mlx_put_pixel(window->img, x, y, BLACK);
}

void	minimap(t_window *window)
{
	int				x;
	int				y;
	t_render_vars	re_vars;

	re_vars.x_offset = floor(((window->player.x / TILE_SIZE) * 16)) \
		- CENTER_CIRCLE;
	re_vars.y_offset = floor(((window->player.y / TILE_SIZE) * 16)) \
		- CENTER_CIRCLE;
	y = 10;
	while (y < MINIMAP_WIDTH)
	{
		x = 10;
		while (x < MINIMAP_HEIGHT)
		{
			re_vars.map_x = (x + re_vars.x_offset) / 16;
			re_vars.map_y = (y + re_vars.y_offset) / 16;
			if ((x - CENTER_CIRCLE) * (x - CENTER_CIRCLE) + \
				(y - CENTER_CIRCLE) * (y - CENTER_CIRCLE) < RADIUS * RADIUS)
				render_minimap(window, &re_vars, x, y);
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
	minimap(window);
	draw_player(window);
}
