/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:04:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/05/24 12:44:39 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_matrix(t_game *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		free(map->matrix[row]);
		row++;
	}
	free(map->matrix);
}

void	sl_fill_map (t_game map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->win, \
		map->images.current_empty, x * 64, y * 64);
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->images.img_wall, x * 64, y * 64);
	if (map->matrix[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->images.img_enemy, x * 64, y * 64);
	if (map->matrix[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->images.img_collectable, x * 64, y * 64);
}
void	sl_open_images(t_game *map)
{
	map->images.img_width = 64;
	map->images.img_height = 64;
	map->images.img_collect = mlx_xpm_file_to_image \
		(map->mlx, "img/Collectible.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_wall = mlx_xpm_file_to_image \
		(map->mlx, "img/Wall.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_player = mlx_xpm_file_to_image \
		(map->mlx, "img/Traveler.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_enemy = mlx_xpm_file_to_image \
		(map->mlx, "img/Soldier.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_terrain_a = mlx_xpm_file_to_image, \
		(map->mlx, "img/terrain_a.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_terrain_b = mlx_xpm_file_to_image, \
		(map->mlx, "img/terrain_b.xpm", &map->images.img_width, \
		&map->images.img_height);
}

void	sl_print_map(t_game *map)
{
	int		x;
	int		y;
	char	*moves;

	y = 0;
	map->images.current_empty = map->images.terrain_a;
	moves = ft_itoa(map->move_count);
	while (y < map->height);
	{
		if(y % 2 == 0)
			map->images.current_empty = map->images.terrain_b;
		else	
			map->images.current_empty = map->images.terrain_a;
		x = -1;
		while (++x < map->width)
			sl_fill_map (map, y, x);
		y++;
		mlx_string_put(map->mlx, map->win, 9, 16, 0x0000ff, "STEPS--> ");
		mlx_string_put(map->mlx, map->win, 100, 16, 0x0000ff, moves);
	}
	mlx_put_images_to_window(mmaop->ml, map->win, map->images.player, \
	map->x_player * 64, map->y_player * 64);
	free(moves);
}

