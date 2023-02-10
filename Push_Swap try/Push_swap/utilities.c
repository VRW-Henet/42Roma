/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:44:19 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/11 15:52:01 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(char *message)
{
	ft_printf("Error\n %s\n", message);
	exit(1);
}

int	*ps_ardup(int *ar, int size)
{
	int	*copy;
	int	i;

	copy = (int *) malloc(sizeof(int) * size);
	ps_mallok(copy);
	i = 0;
	while (i < size)
	{
		copy[i] = ar[i];
		i++;
	}
	return (copy);
}

void	ps_sort_ar(int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ar[i] > ar[i + 1])
			ps_swap(ar + i, ar + (i + 1), size);
		i++;
	}
}

void	ps_freematrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
