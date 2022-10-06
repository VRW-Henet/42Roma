/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:21:45 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 14:23:07 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_shift(int *ar, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		ps_error("size too small, can't rotate");
	size -= 1;
	i = 0;
	temp = ar[0];
	while (i < size)
	{
		ar[i] = ar[i + 1];
		i++;
	}
}

void	ps_shift_a(t_struct *data)
{
	ft_printf("ra\n");
	ps_shift(data->ar_a, data->size_a);
}

void	ps_shift_b(t_struct *data)
{
	ft_printf("rb\n");
	ps_shift(data->ar_b, data->size_b);
}

void	ps_shift_r(t_struct *data)
{
	ft_printf("rr\n");
	ps_shift(data->ar_a, data->size_a);
	ps_shift(data->ar_b, data->size_b);
}
