/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:12:06 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:12:06 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_rotate(int *ar, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = ar[0];
	while (i < size - 1)
	{
		ar[i] = ar[i + 1];
		i++;
	}
	ar[i] = temp;
}

void	ps_rotate_a(t_struct *data)
{
	if (data->size_a <= 1)
		return ;
	ft_printf("ra\n");
	ps_rotate(data->ar_a, data->size_a);
}

void	ps_rotate_b(t_struct *data)
{
	if (data->size_b <= 1)
		return ;
	ft_printf("rb\n");
	ps_rotate(data->ar_b, data->size_b);
}

void	ps_rotate_r(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ft_printf("rr\n");
	ps_rotate(data->ar_a, data->size_a);
	ps_rotate(data->ar_b, data->size_b);
}

void	ps_rr(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ps_rotate(data->ar_a, data->size_a);
	ps_rotate(data->ar_b, data->size_b);
}
