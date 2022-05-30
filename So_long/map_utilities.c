/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:13:59 by dpadrini          #+#    #+#             */
/*   Updated: 2022/05/20 11:48:18 by dpadrini         ###   ########.fr       */
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
	map->mlx = NULL;
	map->move_count = 0;
	map->x_player = 0;
	map->y_player = 0;
	map->victory = NULL;
}

static void	sl_strcpy(char *matrix, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		matrix[i] = str[i];
		i++;
	}
	matrix[i] = '\0';
}

void	sl_matrix(char *selected_map, t_game *map)
{
	int		i;
	int		fd;
	char 	*str;

	i = 0
	fd = open(selected_map, O_RDONLY);
	if (!fd)
		return (0);
	map->height = sl_map_height(selected_map, fd);
	map->width = sl_map_width(selected_map, fd);
	map->matrix = (char **)malloc(sizeof(char *) * map->height + 1);
	map->matrix[map->height] = NULL;
	while (i < map->height)
	{
		map->matrix[i] = (char *)malloc(sizeof(char) * map->width + 1);
		str = get_next_line(fd);
		sl_strcpy(map->matrix[i], str);
		free(str);
		i++;
	}
	if (close (fd) != 0)
		return (0);
}