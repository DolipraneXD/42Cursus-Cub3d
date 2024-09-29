/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:18:00 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 14:42:49 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	close_handler(t_window *window)
{
	mlx_delete_image(window->mlx_con, window->img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	player_direction(mlx_key_data_t keydata, int *key, int value)
{
	if (keydata.action == MLX_RELEASE)
		*key = 0;
	else
		*key = value;
}

void	open_door(t_window *window)
{
	int	new_x;
	int	new_y;
	int	i;

	i = 0;
	while (i < 100)
	{
		new_x = window->player.x + (cos(window->player.rotation_angle) * i);
		new_y = window->player.y + (sin(window->player.rotation_angle) * i);
		if (new_x > 0 && new_y > 0 && new_x < window->width && new_y \
			< window->height && \
			window->map->v_map[new_y / TILE_SIZE][new_x / TILE_SIZE] == 'D')
		{
			window->map->v_map[new_y / TILE_SIZE][new_x / TILE_SIZE] = 'C';
			break ;
		}
		i++;
	}
}

void	close_door(t_window *window)
{
	int	new_x;
	int	new_y;
	int	i;

	i = TILE_SIZE + 1;
	while (i < 100)
	{
		new_x = window->player.x + \
			(cos(window->player.rotation_angle + M_PI) * i);
		new_y = window->player.y + \
			(sin(window->player.rotation_angle + M_PI) * i);
		if (new_x > 0 && new_y > 0 && new_x < window->width \
			&& new_y < window->height && \
			window->map->v_map[new_y / TILE_SIZE][new_x / TILE_SIZE] == 'C')
		{
			window->map->v_map[new_y / TILE_SIZE][new_x / TILE_SIZE] = 'D';
			break ;
		}
		i++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handler(window);
	if (keydata.key == MLX_KEY_O)
		open_door(window);
	else if (keydata.key == MLX_KEY_C)
		close_door(window);
	else if (keydata.key == MLX_KEY_M)
		window->is_mouse_on = false;
	else if (keydata.key == MLX_KEY_N)
		window->is_mouse_on = true;
	else if (keydata.key == MLX_KEY_W)
		player_direction(keydata, &window->player.walk_direction, 1);
	else if (keydata.key == MLX_KEY_S)
		player_direction(keydata, &window->player.walk_direction, -1);
	else if (keydata.key == MLX_KEY_A)
		player_direction(keydata, &window->player.strafe_direction, -1);
	else if (keydata.key == MLX_KEY_D)
		player_direction(keydata, &window->player.strafe_direction, 1);
	else if (keydata.key == MLX_KEY_RIGHT)
		player_direction(keydata, &window->player.turn_direction, 1);
	else if (keydata.key == MLX_KEY_LEFT)
		player_direction(keydata, &window->player.turn_direction, -1);
}
