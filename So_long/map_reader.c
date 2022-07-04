/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:38:15 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/04 11:51:23 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_map_dimensions(t_game *map, int fd)
{
	char	*result;
	int		height;
	int		width;

	result = 0;
	height = 0;
	width = 0;
	result = get_next_line(fd);
	if (!result)
		return ;
	width = ft_strlen(result) - 1;
	while (result != NULL)
	{
		sl_save_map(map, result);
		height++;
		result = get_next_line(fd);
		if (result != NULL)
			sl_width_err(result, width);
	}
	free(result);
	close(fd);
	if (height < 3)
		sl_errors("Ivalid map\nMap shorter than expected");
	map->height = height;
	map->width = width;
}

void	sl_width_err(char *result, int width)
{
	int	i;

	i = ft_strlen(result);
	if (ft_strchr(result, 10) != NULL && result != NULL)
		i--;
	if (i != width && result != NULL)
		sl_errors("Invalid map\nDifferent widths");
}

void	sl_save_map(t_game *map, char *line)
{
	if (map->raw_map == NULL)
		map->raw_map = line;
	else
		map->raw_map = ft_strjoin(map->raw_map, line);
}
