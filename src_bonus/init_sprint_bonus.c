/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:40:59 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/26 11:42:12 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_sword(t_window *window)
{
	int			i;
	const char	*sword_paths[6] = {
		"assets/csword/1.png", "assets/csword/2.png",
		"assets/csword/3.png", "assets/csword/4.png",
		"assets/csword/5.png", "assets/csword/6.png"
	};

	i = 0;
	window->sprite->sword = safe_malloc(sizeof(mlx_texture_t *) * 6);
	window->sprite->sword_i = safe_malloc(sizeof(mlx_image_t) * 6);
	while (i < 6)
	{
		window->sprite->sword[i] = mlx_load_png(sword_paths[i]);
		if (!window->sprite->sword[i])
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		window->sprite->sword_i[i] = mlx_texture_to_image(window->mlx_con,
				window->sprite->sword[i]);
		if (!window->sprite->sword_i[i]
			|| !mlx_resize_image(window->sprite->sword_i[i], WIDTH, HEIGHT))
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		i++;
	}
}

void	init_pickaxe(t_window *window)
{
	int			i;
	const char	*pickaxe_animation[8] = {
		"assets/cpickaxe/1.png", "assets/cpickaxe/2.png",
		"assets/cpickaxe/3.png", "assets/cpickaxe/4.png",
		"assets/cpickaxe/5.png", "assets/cpickaxe/6.png",
		"assets/cpickaxe/7.png", "assets/cpickaxe/8.png"
	};

	window->sprite->pickaxe = safe_malloc(sizeof(mlx_texture_t *) * 8);
	window->sprite->pickaxe_i = safe_malloc(sizeof(mlx_image_t) * 8);
	i = 0;
	while (i < 8)
	{
		window->sprite->pickaxe[i] = mlx_load_png(pickaxe_animation[i]);
		if (!window->sprite->pickaxe[i])
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		window->sprite->pickaxe_i[i] = mlx_texture_to_image(window->mlx_con,
				window->sprite->pickaxe[i]);
		if (!mlx_resize_image(window->sprite->pickaxe_i[i], WIDTH, HEIGHT))
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		i++;
	}
}

void	init_axe(t_window *window)
{
	int			i;
	const char	*axe_animation[6] = {
		"assets/caxe/1.png", "assets/caxe/2.png",
		"assets/caxe/3.png", "assets/caxe/4.png",
		"assets/caxe/5.png", "assets/caxe/6.png"
	};

	window->sprite->axe = safe_malloc(sizeof(mlx_texture_t *) * 6);
	window->sprite->axe_images = safe_malloc(sizeof(mlx_image_t) * 6);
	i = 0;
	while (i < 6)
	{
		window->sprite->axe[i] = mlx_load_png(axe_animation[i]);
		if (!window->sprite->axe[i])
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		window->sprite->axe_images[i] = mlx_texture_to_image(window->mlx_con,
				window->sprite->axe[i]);
		if (!mlx_resize_image(window->sprite->axe_images[i], WIDTH, HEIGHT))
			(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
		i++;
	}
}

void	init_hand(t_window *window)
{
	window->sprite->hand = mlx_load_png("assets/hand.png");
	if (!window->sprite->hand)
		(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
	window->sprite->hand_image = mlx_texture_to_image(window->mlx_con,
			window->sprite->hand);
	if (!window->sprite->hand_image)
		(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
	if (!mlx_resize_image(window->sprite->hand_image, WIDTH, HEIGHT))
		(perror("lead fail"), free_on_error(), exit(EXIT_FAILURE));
}

void	init_sprint(t_window *window)
{
	window->sprite = safe_malloc(sizeof(t_sprite));
	init_helper(window);
	init_sword(window);
	init_pickaxe(window);
	init_axe(window);
	init_hand(window);
}
