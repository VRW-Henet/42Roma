/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:42:27 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/04 12:01:11 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_char(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] != '0' && map->matrix[y][x] != '1' && \
				map->matrix[y][x] != 'E' && map->matrix[y][x] != 'C' && \
				map->matrix[y][x] != 'P' && map->matrix[y][x] != 'F')
			{
				sl_errors("Invalid map:\nInvalid tile detected");
				end_game(map);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	sl_check_perimeter_y(t_game *map)
{
	int	r;
	int	l;
	int	y;

	l = 0;
	r = map->width - 1;
	y = 0;
	while (map->height > y && map->matrix[y][r] == '1' && \
		map->matrix[y][l] == '1')
		y++;
	if (y != map->height)
		return (0);
	return (1);
}

int	sl_check_perimeter_x(t_game *map)
{
	int	top;
	int	bot;
	int	x;

	top = 0;
	bot = map->height - 1;
	x = 0;
	while (map->width > x && map->matrix[top][x] == '1' && \
	map->matrix[bot][x] == '1')
		x++;
	if (x != map->width)
		return (0);
	return (1);
}

void	sl_check_values(t_game *map, int x, int y)
{
	int	i;

	i = 0;
	if (map->matrix[y][x] == 'C')
		map->c++;
	if (map->matrix[y][x] == 'P')
	{
		map->p++;
		map->x_player = x;
		map->y_player = y;
	}
	if (map->matrix[y][x] == 'E')
		map->e++;
}

int	sl_check_inside(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < map->height - 1)
	{
		x = 0;
		while (x++ < map->width - 1)
			sl_check_values(map, x, y);
	}
	if ((map->c + map->p + map->e) < 3)
		sl_errors("map incomplete or non existent");
	if (map->c == 0 || map->e == 0 || map->p != 1)
	{
		sl_errors("Corrupted map\nExpected different values");
		end_game(map);
		return (0);
	}
	return (1);
}
