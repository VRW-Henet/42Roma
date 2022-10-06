/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:53:41 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 14:13:18 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_start_rotation(t_struct *data, int i)
{
	int	n;

	n = (int)(data->ar_a[i]);
	while (data->ar_a[0] != n)
	{
		if (i <= (int)(data->size_a) / 2)
			ps_shift_a(data);
		else
			ps_rev_shift_a(data);
	}
	ps_push_b(data);
}

void	ps_sep(t_struct *data)
{
	int	i;
	int	average;
	int	*ar;

	ar = data->ar_a;
	average = (int)(data->size_a) / 4;
	while (data->size_a != data->best_size && average != 0)
	{
		i = 0;
		while (i < data->size_a)
		{
			if (ps_findlowest(ar[i], data->best_ar, data->best_size) == -1)
			{
				if (ar[i] <= average || average < 3)
				{
					ps_start_rotation(data, i);
					i = -1;
				}
			}
			i++;
		}
		average += ((int)(data->size_a) + (int)(data->size_b)) / 4;
	}
}

void	ps_resolve(t_struct *data)
{
	int	max_size;
	int	*ar_a;

	ar_a = data->ar_a;
	max_size = data->size_a;
	data->ar_b = (int *) malloc (sizeof(int) * max_size);
	ps_mallok(data->ar_b);
	data->size_b = 0;
	if (ps_order(data->ar_a, data->size_a) == 0)
	{
		if (ar_a[0] == 1 || ar_a[1] == 2 || ar_a[2] == 3)
			if (ar_a[2] != 5 && ar_a[0] != 4)
				ps_swap_ab(data->ar_a, data->size_a, "a");
		ps_findcomb(data);
		ps_sep(data);
		free(data->best_ar);
		while (data->size_b != 0)
			ps_engine(data);
		if (ps_findlow(1, data->ar_a, data->size_a) <= (int) data->size_a / 2)
			while (data->ar_a[0] != 1)
				ps_shift_a(data);
		else
			while (data->ar_a[0] != 1)
				ps_rev_rotate_a(data);
	}
}

int	ps_trasformer(int *ar, int size)
{
	int	*temp;
	int	*copy;
	int	i;
	int	j;

	copy = ps_ardup(ar, size);
	temp = (int *) malloc (sizeof(int) * size);
	ps_mallok(temp);
	ps_sort_ar(copy, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (copy[i] != ar[j])
			j++;
		temp[j] = i + 1;
		i++;
	}
	free(ar);
	free(copy);
	return (temp);
}

int	main(int ac, char **av)
{
	t_struct	data;

	if (ac <= 1)
		ps_error("wrong number of parameters");
	if (ac == 2)
		data.ar_a = ps_init_a(av[1], &data.size_a);
	else
	{
		ac -= 1;
		if (ps_filter(&av[1], ac) == 0)
			ps_error("stack values error[b]");
		data.ar_a = ps_init_b(&av[1], ac);
		data.size_a = ac;
	}
	if (ps_check_doubles(data.ar_a, data.size_a) != 0)
		ft_error("doubles detected, check values");
	data.ar_a = ps_trasformer(data.ar_a, data.size_a);
	ps_resolve(&data);
	free(data.ar_a);
	free(data.ar_b);
	return (0);
}
