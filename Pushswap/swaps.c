/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:12:10 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:12:10 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ps_swap_a(t_struct *data)
{
	if (data->size_a <= 1)
		return ;
	ft_printf("sa\n");
	ps_swap(&data->ar_a[0], &data->ar_a[1]);
}

void	ps_swap_b(t_struct *data)
{
	if (data->size_b <= 1)
		return ;
	ft_printf("sb\n");
	ps_swap(&data->ar_b[0], &data->ar_b[1]);
}

void	ps_swap_s(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ft_printf("ss\n");
	ps_swap(&data->ar_a[0], &data->ar_a[1]);
	ps_swap(&data->ar_b[0], &data->ar_b[1]);
}

void	ps_ss(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ps_swap(&data->ar_a[0], &data->ar_a[1]);
	ps_swap(&data->ar_b[0], &data->ar_b[1]);
}
