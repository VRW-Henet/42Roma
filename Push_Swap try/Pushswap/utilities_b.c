/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:12:14 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:12:14 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_piston(t_struct *data)
{
	int	i;

	i = ps_get_a_moves(data, 0, -1, 'a');
	i = ps_posneg_position(data, i, 'a');
	while (i != 0)
	{
		if (i > 0)
		{
			ps_rotate_a(data);
			i--;
		}
		else
		{
			ps_rev_rotate_a(data);
			i++;
		}
	}
}

int	ft_module(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ps_lower_index(int temp[2], int i[2])
{
	int	ap;
	int	bp;
	int	af;
	int	bf;

	ap = ft_module(temp[0]);
	bp = ft_module(temp[1]);
	af = ft_module(i[0]);
	bf = ft_module(i[1]);
	if (ap + bp < af + bf)
		return (1);
	return (0);
}

void	ps_get_stack_infos(t_struct *data, int *top, int *size, char stack)
{
	*top = 0;
	if (stack == 'a')
		*size = (int)data->size_a;
	else if (stack == 'b')
		*size = data->size_b;
}

int	ps_get_id(t_struct *data, int i, char stack)
{
	int	top;
	int	size;
	int	bot;

	ps_get_stack_infos(data, &top, &size, stack);
	i++;
	i = i % data->size_a;
	return (i);
}
