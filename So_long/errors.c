/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:57:12 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/22 14:46:29 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_errors(char *m)
{
	ft_putstr("Something went wrong\n");
	ft_putstr(m);
	ft_putstr("\n");
	exit (0);
}

void	sl_err_alignement(int fd, int width)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i != width)
			sl_errors("Invalid map:\nnot aligned");
	}
	free(str);
}
