/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmidmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:35 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:23:52 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min(t_struct *data)
{
	int	*ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (ar[i] < ret)
			ret = ar[i];
		i++;
	}
	return (ret);
}

int	get_max(t_struct *data)
{
	int	*ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (ar[i] > ret)
			ret = ar[i];
		i++;
	}
	return (ret);
}

int	get_mid(t_struct *data, int bval)
{
	int	*ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (bval > ar[i] && (i + 1) < data->size_a && bval < ar[i + 1])
		{
			ret = ar[i + 1];
			break ;
		}
		i++;
	}
	return (ret);
}

int	minmidmax(t_struct *data, int bval)
{
	int	min;
	int	mid;
	int	max;

	min = get_min(data);
	if (bval < min)
		return (ps_posneg_position(data, min, 'a'));
	max = get_max(data);
	if (bval > max)
		return (ps_posneg_position(data, min, 'a'));
	mid = get_mid(data, bval);
	return (ps_posneg_position(data, mid, 'a'));
}
