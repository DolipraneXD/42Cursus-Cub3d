/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:04:05 by mal-mora          #+#    #+#             */
/*   Updated: 2024/09/22 12:37:39 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	get_step(double dx, double dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	else
		return (fabs(dy));
}

void	detect_door(t_ray *ray, t_window *window)
{
	int	x_new;
	int	y_new;

	x_new = ray->wall_hit_x;
	y_new = ray->wall_hit_y;
	if (ray->is_facing_left && !ray->was_hit_horz)
		x_new--;
	if (ray->is_facing_up && ray->was_hit_horz)
		y_new--;
	if (y_new > 0 && x_new > 0 && x_new < WIDTH && y_new < HEIGHT && \
		window->map->v_map[(int)y_new / TILE_SIZE][(int)x_new / \
		TILE_SIZE] == 'D')
		ray->is_door = true;
}

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	angle = fmod(angle, 2 * M_PI);
	return (angle);
}

void	init_horz_cast(t_ray_cast *ray_cast, t_window *window, t_ray *ray)
{
	ray_cast->yinter = floor(window->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		ray_cast->yinter += TILE_SIZE;
	else
		ray_cast->yinter += 0;
	ray_cast->xinter = window->player.x + \
		(ray_cast->yinter - window->player.y) / tan(ray->ray_angle);
	ray_cast->ystep = TILE_SIZE;
	if (ray->is_facing_up)
		ray_cast->ystep *= -1;
	else
		ray_cast->ystep *= 1;
	ray_cast->xstep = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_facing_left && ray_cast->xstep > 0)
		ray_cast->xstep *= -1;
	else
		ray_cast->xstep *= 1;
	if (ray->is_facing_right && ray_cast->xstep < 0)
		ray_cast->xstep *= -1;
	else
		ray_cast->xstep *= 1;
}

void	init_vert_cast(t_ray_cast *ray_var, t_window *window, t_ray *ray)
{
	ray_var->xinter = floor(window->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		ray_var->xinter += TILE_SIZE;
	else
		ray_var->xinter += 0;
	ray_var->yinter = window->player.y + \
		(ray_var->xinter - window->player.x) * tan(ray->ray_angle);
	ray_var->xstep = TILE_SIZE;
	if (ray->is_facing_left)
		ray_var->xstep *= -1;
	else
		ray_var->xstep *= 1;
	ray_var->ystep = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && ray_var->ystep > 0)
		ray_var->ystep *= -1;
	else
		ray_var->ystep *= 1;
	if (ray->is_facing_down && ray_var->ystep < 0)
		ray_var->ystep *= -1;
	else
		ray_var->ystep *= 1;
}
