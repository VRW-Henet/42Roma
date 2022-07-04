/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:13:59 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/04 11:35:43 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_struct_allocation(t_game *map)
{
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->height = 0;
	map->width = 0;
	map->matrix = 0;
	map->raw_map = NULL;
	map->mlx = mlx_init();
	map->move_count = 0;
	map->x_player = 0;
	map->y_player = 0;
	map->window = NULL;
}

void	sl_matrix(char *selected_map, t_game *map)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(selected_map, O_RDONLY);
	if (!fd)
		return ;
	sl_map_dimensions(map, fd);
	map->matrix = (char **)malloc(sizeof(char *) * map->height + 1);
	if (!map->matrix)
	{
		ft_printf("Matrix allocation error");
		return ;
	}
	map->matrix[map->height] = NULL;
	while (i < map->height)
	{
		map->matrix[i] = (char *)malloc(sizeof(char) * map->width + 1);
		sl_get_lines(map, i, map->matrix[i]);
		i++;
	}
	if (close (fd) != 0)
		return ;
}

void	sl_get_lines(t_game *map, int n, char *str)
{
	char	*grid;
	int		i;
	int		j;

	grid = map->raw_map;
	j = 0;
	i = 0;
	if (grid == NULL)
		return ;
	while (n > 0)
	{
		i++;
		if (grid[i] == '\n')
		{
			n--;
			i++;
		}
	}
	while (grid[i] != '\n' && grid[i] != '\0')
		str[j++] = grid[i++];
	str[j] = '\0';
}

void	sl_check_name(char *name)
{
	int	l;

	l = ft_strlen(name);
	ft_printf("opening %s\n", name);
	if (!ft_strnstr(name, "maps/", l) || \
	(ft_strnstr(name, "maps/", l) && name[l] != '\0'))
		sl_errors("use './so_long maps/<map name>'");
	if (!ft_strnstr(name, ".ber", l) || \
	(ft_strnstr(name, ".ber", l) && name[l] != '\0'))
		sl_errors("invalid map name, try adding '.ber' at the end");
}
