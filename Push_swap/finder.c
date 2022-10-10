/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:11 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/10 12:14:04 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_findmin(int *ar, int size)
{
	int	ret;

	ret = ps_findlow(ps_min(ar, size), ar, size);
	if (ret == -1)
		ps_error("not an expected error, check findmin");
	return (ret);
}

int	ps_min(int *ar, int size)
{
	int	min;
	int	i;

	min = ar[0];
	i = 1;
	while (i < size)
	{
		if (ar[i] < min)
			min = ar[i];
		i++;
	}
	return (min);
}

int	ps_findlow(int n, int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ar[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
