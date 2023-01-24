/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:26 by dpadrini          #+#    #+#             */
/*   Updated: 2023/01/20 16:07:33 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *str)
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
	return (r * s);
}
