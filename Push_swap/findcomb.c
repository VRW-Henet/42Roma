/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcomb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:33:19 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 12:39:51 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_findcomb(t_struct *data)
{
	int	**comb;
	int	i;
	int	r;

	comb = ps_newcomb(data);
	r = 1;
	i = ps_findmin(data->ar_a, data->size_a);
	i++;
	if (i == data->size_a)
		i = 0;
	while (data->ar_a[i] != 1)
	{
		if (data->ar_a[i] > comb[r - 1][r - 1])
			comb[r - 1] = ps_clone_add(comb[r - 1], &r, data->ar_a[i]);
		else
			ps_between(comb, data->ar_a[i]);
		i++;
		if (i == data->size_a)
			i = 0;
	}
	data->best_ar = ps_ardup(comb[r - 1], r);
	data->best_size = r;
	ps_freematrix(comb, r);
}

int	**ps_newcomb(t_struct *data)
{
	int	**comb;
	int	size_a;

	size_a = data->size_a;
	comb = (int **) malloc (sizeof(int *) * size_a);
	ps_mallok(comb);
	comb[0] = (int *) malloc (sizeof(int));
	ps_mallok(comb[0]);
	comb[0][0] = 1;
	return (comb);
}

int	*ps_clone_add(int *ar, int *len, int n)
{
	int	*arr;
	int	i;

	arr = (int *) malloc (sizeof(int) * (*len + 1));
	ps_mallok(arr);
	i = 0;
	while (i < *len)
	{
		arr[i] = ar[i];
		i++;
	}
	arr[i] = n;
	(*len)++;
	return (arr);
}

void	ps_between(int **comb, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (comb[i][i] < num)
		i++;
	while (j < i)
	{
		comb[i][j] = comb[i - 1][j];
		j++;
	}
	comb[i][j] = num;
}
