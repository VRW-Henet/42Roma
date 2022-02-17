/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:53:16 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/17 14:33:18 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	len_num(long long n)
{
	int	result;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	result = 0;
	if (n < 0)
		result = 1;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

int	len_num_hex(unsigned long n)
{
	int	result;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	result = 0;
	while (n)
	{
		result++;
		n /= 16;
	}
	return (result);
}

int	ft_putnbr(long long int n, t_flag *flag)
{
	char	result[18];
	int		i;

	if (flag->poin && flag->accuracy == 0 && n == 0)
		return (0);
	i = 1;
	if (n == 0)
		printchar('0', flag);
	if (n < 0)
	{
		n = -n;
		if (!flag->zero && !flag->poin)
			printchar('-', flag);
	}
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i)
		printchar(result[i--], flag);
	return (0);
}

void	putnbr_ptr(unsigned long num, char *base, t_flag *flag)
{
	char	result[18];
	int		i;

	i = 1;
	while (num)
	{
		result[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	if (i)
		ft_putstr("0x", flag);
	while (i)
	{
		ft_putchar(result[i], flag);
		i--;
	}
}


