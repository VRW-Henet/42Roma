/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:04:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/04 10:17:17 by dpadrini         ###   ########.fr       */
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

void	sl_fill_map(t_game *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->window, \
		map->images.current_empty, x * 64, y * 64);
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_wall, x * 64, y * 64);
	if (map->matrix[y][x] == 'F')
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_enemy, x * 64, y * 64);
	if (map->matrix[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_collectable, x * 64, y * 64);
	if (map->matrix[y][x] == 'E' && map->c == 0)
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_exit, x * 64, y * 64);
	else if (map->matrix[y][x] == 'E' && map->c != 0)
		mlx_put_image_to_window(map->mlx, map->window, \
		map->images.img_time_machine, x * 64, y * 64);
}

void	sl_open_images(t_game *map)
{
	map->images.img_width = 64;
	map->images.img_height = 64;
	map->images.img_collectable = mlx_xpm_file_to_image \
		(map->mlx, "img/Collectable.xpm", &map->images.img_width, \
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
	map->images.img_terrain_a = mlx_xpm_file_to_image \
		(map->mlx, "img/terrain_a.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_w_player = mlx_xpm_file_to_image \
		(map->mlx, "img/Traveler_2.xpm", &map->images.img_width, \
		&map->images.img_height);
	sl_img_exit(map);
}

void	sl_img_exit(t_game *map)
{
	map->images.img_exit = mlx_xpm_file_to_image \
		(map->mlx, "img/images_exit.xpm", &map->images.img_width, \
		&map->images.img_height);
	map->images.img_time_machine = mlx_xpm_file_to_image \
		(map->mlx, "img/Time-machine.xpm", &map->images.img_width, \
		&map->images.img_height);
}

void	sl_print_map(t_game *map)
{
	int		x;
	int		y;
	char	*moves;

	y = 0;
	map->images.current_empty = map->images.img_terrain_a;
	moves = ft_itoa(map->move_count);
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
			sl_fill_map (map, y, x);
		y++;
		mlx_string_put(map->mlx, map->window, 9, 16, 0xffffff, "STEPS--> ");
		mlx_string_put(map->mlx, map->window, 100, 16, 0xffffff, moves);
	}
	mlx_put_image_to_window(map->mlx, map->window, map->images.img_player, \
	map->x_player * 64, map->y_player * 64);
	free(moves);
}
