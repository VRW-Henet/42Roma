/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:06 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:06 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_push_first_sequence(t_struct *data, t_short *best)
{
	int	size;

	size = data->size_a;
	while (size >= 0)
	{
		if (data->ar_a[0] <= best->highmid_value)
		{
			if (data->ar_a[0] <= best->lowmid_value)
			{
				ps_push_b(data);
				if (data->ar_a[0] > best->highmid_value)
					ps_rotate_r(data);
				else
					ps_rotate_b(data);
			}
			else
				ps_push_b(data);
		}
		else
			ps_rotate_a(data);
		size--;
	}
}

void	ps_exe_last_sequence(t_struct *data, t_short *best)
{
	while (data->size_a > 3)
		ps_push_b(data);
	if (!(data->ar_a[0] < data->ar_a[1] && data->ar_a[1] < data->ar_a[2]))
		ps_order_three(data);
}

void	ps_order_three(t_struct *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->ar_a[0];
	mid = data->ar_a[1];
	bot = data->ar_a[2];
	if (top > bot && top > mid && bot > mid)
		ps_rotate_a(data);
	else if (top > bot && mid > top && mid > bot)
		ps_rev_rotate_a(data);
	else if (top > mid && bot > top && bot > mid)
		ps_swap_a(data);
	else if (mid > top && mid > bot && bot > top)
	{
		ps_swap_a(data);
		ps_rotate_a(data);
	}
	else if (top > mid && mid > bot && top > bot)
	{
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
}

void	ps_pull(t_struct *data, t_short *best)
{
	int	i[2];

	i[0] = -1;
	i[1] = -1;
	while (data->size_b > 0)
	{	
		ps_fake_pull(data, i);
		ps_circuit(data, i);
		ps_push_a(data);
	}
	ps_piston(data);
}

void	ps_circuit(t_struct *data, int i[2])
{
	while (i[0] != 0 || i[1] != 0)
	{
		if (i[0] > 0 && i[1] > 0 && i[0]-- && i[1]--)
			ps_rotate_r(data);
		else if (i[0] < 0 && i[1] < 0 && i[0]++ && i[1]++)
			ps_rev_rotate_r(data);
		if (i[1] <= 0 && i[0] > 0 && i[0]--)
			ps_rotate_a(data);
		else if (i[1] >= 0 && i[0] < 0 && i[0]++)
			ps_rev_rotate_a(data);
		if (i[0] <= 0 && i[1] > 0 && i[1]--)
			ps_rotate_b(data);
		else if (i[0] >= 0 && i[1] < 0 && i[1]++)
			ps_rev_rotate_b(data);
	}
}
