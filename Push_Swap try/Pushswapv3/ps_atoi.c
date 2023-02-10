/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:09:20 by dpadrini          #+#    #+#             */
/*   Updated: 2023/01/20 16:45:26 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_atoi2(const char *str, int i)
{
	int	s;

	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	return (s);
}

int	ps_atoi(const char *str, t_struct *data, t_short *best)
{
	int					i;
	int					s;
	unsigned long long	r;

	i = 0;
	r = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	s = ft_atoi2(str, i);
	if (s == 0)
		return (0);
	while (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		r = r * 10 + (str[i++] - 48);
	if (r > 2147483647)
		ps_error(data, best);
	return (r * s);
}
