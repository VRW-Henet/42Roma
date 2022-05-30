/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:38:15 by dpadrini          #+#    #+#             */
/*   Updated: 2022/05/20 11:48:17 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_map_height(char *selected_map, int fd)
{
	char	*result;
	int		height;

	result = 0;
	height = 0;
	result = get_next_line(fd);
	while (result != NULL)
	{
		height++;
		free(result);
		result = get_next_line(fd);
	}
	free(result);
	close(fd);
	if(height < 3)
		sl_errors("Ivalid map\nTry another one");
	return (height);
}

int	sl_map_width(char *selected_map, int fd)
{
	char	*result;
	int		width;

	width = 0;
	result = get_next_line(fd);
	width = ft_strlen(result) - 1;
	sl_err_alignement(fd, width);
	if (width < 3)
		sl_errors("Invalid map\nMap too smöl")
	return (width);
}