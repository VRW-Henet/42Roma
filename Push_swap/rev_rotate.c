/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:19:36 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 14:21:19 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rev_shift(int *ar, int size)
{
	int	temp;

	size -= 1;
	temp = ar[size];
	while (size > 0)
	{
		ar[size] = ar[size - 1];
		size--;
	}
	ar[size] = temp;
}

void	ps_rev_shift_a(t_struct *data)
{
	ft_printf("rra\n");
	ps_rev_shift(data->ar_a, data->size_a);
}

void	ps_rev_shift_b(t_struct *data)
{
	ft_printf("rrb\n");
	ps_rev_shift(data->ar_b, data->size_b);
}

void	ps_rev_shift_r(t_struct *data)
{
	ft_printf("rrr\n");
	ps_rev_shift(data->ar_a, data->size_a);
	ps_rev_shift(data->ar_b, data->size_b);
}
