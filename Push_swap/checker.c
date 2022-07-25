/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:38:30 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/25 16:37:43 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int	ps_filter(char **matrix, int size)
{
	int	x;
	int	y;

	row = 0;
	while (row < size)
	{
		col = 0;
		if (matrix[x][y] == '-' || matrix[x][y] == '+')
			col += 1;
		if (matrix[x][y] == '\0')
			return (0);
		while (matrix[x][y] != '\0')
		{
			if (ft_isdigit(matrix[x][y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ps_mallok(void *ptr)
{
	if (ptr == NULL)
		ps_error();
}

int	ps_limit(char *str)
{
	long long int	nb;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	if (str[i] == '-'|| str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nb = 0;
	while (str[i] != '\0')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	nb *= sign;
	if (nb > 2147483647 || nb < -2147483648)
		ps_error();
}