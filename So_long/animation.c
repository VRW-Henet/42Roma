/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:12:48 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/28 16:05:53 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_animate(t_game *map)
{
	static int	clock;

	if (!clock)
		clock = 0;
	clock++;
	if (clock % 8000 == 0)
	{
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_terrain_a, map->x_player * 64, map->y_player * 64);
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_player, map->x_player * 64, map->y_player * 64);
	}
	else if (clock % 4000 == 0)
	{
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_terrain_a, map->x_player * 64, map->y_player * 64);
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_w_player, map->x_player * 64, map->y_player * 64);
	}
	else if (clock == 8000)
		clock = 0;
	return (0);
}
