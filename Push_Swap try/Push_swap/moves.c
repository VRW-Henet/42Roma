/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:43:03 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/10 12:22:56 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_engine(t_struct *data)
{
	t_shortest	small;
	int			*ar_a;
	int			*ar_b;

	small = ps_find_short(data);
	ar_a = data->ar_a;
	ar_b = data->ar_b;
	while ((ar_a[0] != small.na && ar_b[0] \
		!= small.nb) && small.dir_a == small.dir_b)
	{
		if (small.dir_a == 0)
			ps_shift_r(data);
		else
			ps_rev_shift_r(data);
	}
	while (ar_a[0] != small.na && small.dir_a == 0)
		ps_shift_a(data);
	while (ar_a[0] != small.na && small.dir_a == 1)
		ps_rev_shift_a(data);
	while (ar_b[0] != small.nb && small.dir_b == 0)
		ps_shift_b(data);
	while (ar_b[0] != small.nb && small.dir_b == 1)
		ps_rev_shift_b(data);
	ps_push_a(data);
}

t_shortest	ps_find_short(t_struct *data)
{
	t_shortest	min;
	t_shortest	*small;
	int			i;

	small = (t_shortest *) malloc (sizeof(t_shortest) * data->size_b);
	i = 0;
	while (i < data->size_b)
	{
		ps_makestruct(&small[i], data, i);
		i++;
	}
	min = small[0];
	i = 1;
	while (i < data->size_b)
	{
		if (min.count > small[i].count)
			min = small[i];
		i++;
	}
	free(small);
	return (min);
}

void	ps_makestruct(t_shortest *small, t_struct *data, int i)
{
	small->nb = data->ar_b[i];
	ps_direction(&small->dir_b, &small->moves_b, data->size_b, i);
	ps_moves(data, small);
	if (small->moves_a <= small->moves_b \
		&& small->dir_a == small->dir_b)
		small->count = small->moves_a;
	else if (small->moves_a > small->moves_b \
		&& small->dir_a == small->dir_b)
		small->count = small->moves_b;
	else if (small->dir_a != small->dir_b)
		small->count = small->moves_b + small->moves_a;
}

void	ps_direction(int *dir, int *moves, int size, int i)
{
	*dir = 0;
	*moves = i;
	if (i > size / 2)
	{
		*dir = 1;
		*moves = size - 1;
	}
}

void	ps_moves(t_struct *data, t_shortest *small)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		if (j == data->size_a)
			j = 0;
		if (data->ar_a[i] < small->nb && data->ar_a[j] > small->nb)
		{
			small->na = data->ar_a[j];
			ps_direction(&small->dir_a, &small->moves_a, data->size_a, j);
			return ;
		}
		if (data->ar_a[i] == 1)
			x = i;
		i++;
	}
	small->na = 1;
	ps_direction(&small->dir_a, &small->moves_a, data->size_a, x);
}
