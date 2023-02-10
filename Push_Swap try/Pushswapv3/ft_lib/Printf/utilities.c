/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:46:15 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/24 07:11:25 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->leng++;
}

void	printstr(char *str, t_flag *flag)
{
	int	len;

	if (str)
	{
		len = pf_strlen(str);
		if (flag->poin && flag->prec < len)
			len = flag->prec;
		write(1, str, len);
		flag->leng += len;
	}
}

void	print_stuff(int n, t_flag *flag, int io)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (flag->zero || io == 0)
			printchar('0', flag);
		else
			printchar(' ', flag);
		i++;
	}
}

void	printsymbol(int num, int n, t_flag *flag)
{
	int	c;

	c = len_num(num);
	if (len_num(num) < flag->prec)
		c = flag->prec;
	if (num < 0 && (flag->zero || flag->poin))
		printchar('-', flag);
	if (flag->widt > c && (!flag->minu && !flag->zero))
		print_stuff(flag->widt - n, flag, 1);
	if (flag->plus && num >= 0)
		printchar('+', flag);
	if (flag->spce && num >= 0 && !flag->plus)
		printchar(' ', flag);
	if (flag->prec > len_num(num))
		print_stuff(flag->prec - len_num(num), flag, 0);
	if (flag->widt > c && !flag->minu && flag->zero)
		print_stuff(flag->widt - n, flag, 0);
}

void	print_hex(char c, long long num, int n, t_flag *flag)
{
	if (num < 0 && (flag->zero || flag->poin))
		printchar('-', flag);
	if (flag->widt && !flag->minu)
		print_stuff(flag->widt - n, flag, 0);
	if (flag->plus && num >= 0)
		printchar('+', flag);
	if (flag->spce && num >= 0 && !flag->plus)
		printchar(' ', flag);
	if (flag->prec > len_num_hex(num))
		print_stuff(flag->prec - len_num_hex(num), flag, 0);
	if (flag->hash && num != 0)
	{
		if (c == 'x')
			printstr("0x", flag);
		else
			printstr("0X", flag);
	}	
}
