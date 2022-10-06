/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:25 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 14:19:08 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a == 0)
		ps_error("can't push, missing size.");
	i = *size_b;
	while (i > 0)
	{
		ar_b[i] == ar_b[i - 1];
		i--;
	}
	i = 0;
	ar_b[i] = ar_a[i];
	*size_b += 1;
	*size_a -= 1;
	while (i < *size_a)
	{
	ar_a[i] = ar_a[i + 1];
		i++;
	}
}

void	ps_push_a(t_struct *data)
{
	ft_printf("pa\n");
	ps_push(data->ar_b, data->ar_a, &data->size_b, &data->size_a);
}

void	ps_push_b(t_struct *data)
{
	ft_printf("pb\n");
	ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
}
