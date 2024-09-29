/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:16:24 by mal-mora          #+#    #+#             */
/*   Updated: 2024/09/22 13:44:29 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_hit_wall(t_window *window, double new_x, double new_y)
{
	if (check_hits(window, new_x, new_y, 0) && \
		check_hits(window, new_x + PLAYER_SIZE, new_y, 0) && \
		check_hits(window, new_x, new_y + PLAYER_SIZE, 0) && \
		check_hits(window, new_x - PLAYER_SIZE, new_y - PLAYER_SIZE, 0) && \
		check_hits(window, new_x, new_y - PLAYER_SIZE, 0) && \
		check_hits(window, new_x - PLAYER_SIZE, new_y, 0) && \
		check_hits(window, new_x + PLAYER_SIZE, new_y + PLAYER_SIZE, 0))
		return (true);
	else
		return (false);
}

void	update_player(t_window *window)
{
	int		move_step;
	int		strafe_step;
	double	new_x;
	double	new_y;

	window->player.rotation_angle += (window->player.turn_direction \
		* window->player.turn_speed);
	move_step = window->player.walk_direction * \
		window->player.walk_speed;
	strafe_step = window->player.strafe_direction \
		* window->player.walk_speed;
	new_x = window->player.x + (cos(window->player.rotation_angle) \
		* move_step) - (sin(window->player.rotation_angle) * strafe_step);
	new_y = window->player.y + (sin(window->player.rotation_angle) \
		* move_step) + (cos(window->player.rotation_angle) * strafe_step);
	if (is_hit_wall(window, new_x, new_y))
	{
		window->player.y = new_y;
		window->player.x = new_x;
	}
}
