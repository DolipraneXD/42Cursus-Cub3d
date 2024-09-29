/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:17:40 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/29 08:19:56 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	loop_func(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	update_player(window);
	render(window);
}

static void	display_window(t_window *window)
{
	init_window(window);
	init_player(&window->player, window->map);
	init_texture(window);
	mlx_loop_hook(window->mlx_con, loop_func, window);
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
	return (0);
}
