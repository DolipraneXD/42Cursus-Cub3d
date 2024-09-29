/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:05:10 by mal-mora          #+#    #+#             */
/*   Updated: 2024/09/29 08:20:30 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	handle_mouse_rotation(t_window *window)
{
	int	x;
	int	y;
	int	delta_x;

	mlx_get_mouse_pos(window->mlx_con, &x, &y);
	delta_x = (x - WIDTH / 2) / 8;
	window->player.rotation_angle += delta_x * 0.01;
	mlx_set_mouse_pos(window->mlx_con, WIDTH / 2, HEIGHT / 2);
}

static void	loop_func(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	update_player(window);
	if (window->is_mouse_on)
	{
		handle_mouse_rotation(window);
		mlx_set_cursor_mode(window->mlx_con, MLX_MOUSE_HIDDEN);
	}
	else
		mlx_set_cursor_mode(window->mlx_con, MLX_MOUSE_NORMAL);
	render(window);
}

static void	display_window(t_window *window)
{
	init_window(window);
	init_player(&window->player, window->map);
	init_texture(window);
	init_sprint(window);
	mlx_set_mouse_pos(window->mlx_con, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(window->mlx_con, loop_func, window);
	mlx_loop_hook(window->mlx_con, ft_sprint, window);
	mlx_key_hook(window->mlx_con, my_keyhook, window);
	mlx_loop(window->mlx_con);
}

int	main(int argc, char *argv[])
{
	t_window	window;
	t_map		*map;

	if (argc != 2)
		ft_error(NULL, 1);
	map = malloc(sizeof (t_map));
	if (!map)
		exit(EXIT_FAILURE);
	map_init(map);
	check_read_map(argv[1], map);
	window.map = map;
	data_grep(&window);
	display_window(&window);
	free_map(map);
	return (0);
}
