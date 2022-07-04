/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:33:02 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/04 10:45:26 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move_up(t_game *map)
{
	if (map->matrix[map->y_player - 1][map->x_player] != '1' \
		&& (map->matrix[map->y_player - 1][map->x_player] != 'E' \
		|| map->c == 0))
	{
		if (map->matrix[map->y_player - 1][map->x_player] == 'C')
			map->c--;
		if (map->matrix[map->y_player - 1][map->x_player] == 'E')
			end_game(map);
		if (map->matrix[map->y_player - 1][map->x_player] == 'F')
		{
			ft_printf("A soldier got you, the end is near.\n");
			end_game(map);
		}
		map->move_count += 1;
		map->matrix[map->y_player][map->x_player] = '0';
		map->matrix[map->y_player - 1][map->x_player] = 'P';
		map->y_player -= 1;
		ft_printf("MOVES --> %d\n", map->move_count);
	}	
}

void	sl_move_down(t_game *map)
{
	if (map->matrix[map->y_player + 1][map->x_player] != '1' \
		&& (map->matrix[map->y_player + 1][map->x_player] != 'E' \
		|| map->c == 0))
	{
		if (map->matrix[map->y_player + 1][map->x_player] == 'C')
			map->c--;
		if (map->matrix[map->y_player + 1][map->x_player] == 'E')
			end_game(map);
		if (map->matrix[map->y_player + 1][map->x_player] == 'F')
		{
			ft_printf("A soldier got you, the end is near.\n");
			end_game(map);
		}
		map->move_count += 1;
		map->matrix[map->y_player][map->x_player] = '0';
		map->matrix[map->y_player + 1][map->x_player] = 'P';
		map->y_player += 1;
		ft_printf("MOVES --> %d\n", map->move_count);
	}
}

void	sl_move_left(t_game *map)
{
	if (map->matrix[map->y_player][map->x_player - 1] != '1' \
		&& (map->matrix[map->y_player][map->x_player - 1] != 'E' \
		|| map->c == 0))
	{
		if (map->matrix[map->y_player][map->x_player - 1] == 'C')
			map->c--;
		if (map->matrix[map->y_player][map->x_player - 1] == 'E')
			end_game(map);
		if (map->matrix[map->y_player][map->x_player - 1] == 'F')
		{
			ft_printf("A soldier got you, the end is near.\n");
			end_game(map);
		}
		map->move_count += 1;
		map->matrix[map->y_player][map->x_player] = '0';
		map->matrix[map->y_player][map->x_player - 1] = 'P';
		map->x_player -= 1;
		ft_printf("MOVES --> %d\n", map->move_count);
	}
}

void	sl_move_right(t_game *map)
{
	if (map->matrix[map->y_player][map->x_player + 1] != '1' \
		&& (map->matrix[map->y_player][map->x_player + 1] != 'E' \
		|| map->c == 0))
	{
		if (map->matrix[map->y_player][map->x_player + 1] == 'C')
			map->c--;
		if (map->matrix[map->y_player][map->x_player + 1] == 'E')
			end_game(map);
		if (map->matrix[map->y_player][map->x_player + 1] == 'F')
		{
			ft_printf("A soldier got you, the end is near.\n");
			end_game(map);
		}
		map->move_count += 1;
		map->matrix[map->y_player][map->x_player] = '0';
		map->matrix[map->y_player][map->x_player + 1] = 'P';
		map->x_player += 1;
		ft_printf("MOVES --> %d\n", map->move_count);
	}
}
