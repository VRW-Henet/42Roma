/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:21 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/20 14:43:51 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	sl_hooks(int key, t_game *map)
{
	if (key == 53)
		end_game(map);
	if (key == 13)
		sl_move_up(map);
	else if (key == 0)
		sl_move_left(map);
	else if (key == 2)
		sl_move_right(map);
	else if (key == 1)
		sl_move_down(map);
	ft_printf("MOVES --> %d\n", map->move_count);
	sl_print_map(map);
	return (0);
}

int	sl_exit(char *str)
{
	ft_putstr_fd(str, 0);
	exit (0);
}


void	end_game(t_game *map)
{
	mlx_destroy_window(map->mlx, map->victory);
	sl_free_matrix(map);
	exit(0);
}

int	sl_check_map(t_game *map)
{
	if (sl_check_char(map) != 1)
		return (0);
	else if (sl_check_perimeter_y(map) != 1)
		return (0);
	else if (sl_check_perimeter_x(map) != 1)
		return (0);
	else if (sl_check_inside(map) != 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	map;

	if(argc != 2)
		ft_putstr("Incorrect inputs\nType: './so_long <map>'");
	sl_struct_allocation(&map);
	sl_matrix(argv[1], &map);
	sl_check_map(&map);
	map.mlx = mlx_init();
	sl_open_images(&map);
	map.victory = mlx_new_window(map.mlx, map.width * 64, \
		map.height * 64, "Get the ash and leave!");
	sl_print_map(&map);
	mlx_hook(map.victory, 2, (1 >> 1L), sl_hooks, &map);
	mlx_hook(map.victory, 17, 0, sl_exit, 0);
	mlx_do_key_autorepeaton(map.mlx);
	mlx_loop(map.mlx);	
}