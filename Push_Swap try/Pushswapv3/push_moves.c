/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:41 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:41 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b)
{
	int	i;

	i = *size_b;
	while (i > 0)
	{
		ar_b[i] = ar_b[i - 1];
		i--;
	}
	i = 0;
	*size_b += 1;
	ar_b[i] = ar_a[i];
	while (i < *size_a)
	{
		ar_a[i] = ar_a[i + 1];
		i++;
	}
	*size_a -= 1;
	ar_a[*size_a] = 0;
}

void	ps_push_a(t_struct *data)
{
	if (data->size_b < 1)
		return ;
	ft_printf("pa\n");
	ps_push(data->ar_b, data->ar_a, &data->size_b, &data->size_a);
}

void	ps_push_b(t_struct *data)
{
	if (data->size_a < 1)
		return ;
	ft_printf("pb\n");
	ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
}
