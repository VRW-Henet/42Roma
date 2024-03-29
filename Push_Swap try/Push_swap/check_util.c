/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:31:08 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/14 13:00:53 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_filter(char **matrix, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		if (matrix[x][y] == '-' || matrix[x][y] == '+')
			y += 1;
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
		ps_error("malloc failed");
}

void	ps_limit(char *str)
{
	long long int	nb;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
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
		ps_error("values over the limits");
}

int	ps_check_doubles(int *ar, int size)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("io qua parto\n");
	ft_printf("%d\n", size);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ar[i] == ar[j])
			{
				ft_printf("e qua mi romp\n");
				return (1);
			}
			ft_printf("qua vado");
			j++;
		}
		i++;
	}
	ft_printf("e qua mi chiudo\n");
	return (0);
}

int	ps_order(int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ar[i] > ar[i + 1])
			return (0);
		i++;
	}
	return (1);
}
