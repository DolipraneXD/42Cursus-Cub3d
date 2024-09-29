/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:23 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 10:39:31 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	select_weapon(t_window *window, int frames, int weapen)
{
	window->sprite->enabled = true;
	window->sprite->num_frames = frames;
	window->sprite->whatison = weapen;
}

void	display_hand(t_window *window)
{
	if (window->sprite->hand_on == false)
	{
		window->sprite->current_animation_images = &window->sprite->hand_image;
		window->sprite->num_frames = 1;
		window->sprite->enabled = true;
		window->sprite->hand_on = true;
	}
}
