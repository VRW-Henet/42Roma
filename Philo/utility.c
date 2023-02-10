/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:17:45 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:19:03 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_error(void)
{
	write(2, "error\n", 6);
	return (1);
}

int	ph_limits(long long nb)
{
	if (nb < 0 || nb > 2147483647)
		return (1);
	return (0);
}

int	ph_checker(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (argv[i][j] == '+')
			j++;
		if (argv[i][j] <= '0' || argv[i][j] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ph_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	nb *= sign;
	return (nb);
}
