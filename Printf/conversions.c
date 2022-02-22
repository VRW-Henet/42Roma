/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:55:29 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/22 11:44:57 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int i, va_list args, t_flag *flag)
{
	char	ch;

	ch = va_arg(args, int);
	if (flag->widt && !flag->minu)
	{
		print_stuff(flag->widt - 1, flag, 1);
		printchar(ch, flag);
	}
	else if (flag->widt && flag->minu)
	{
		printchar(ch, flag);
		print_stuff(flag->widt - 1, flag, 1);
	}
	else
		printchar(ch, flag);
	i++;
	return (i);
}

int	print_s(int i, char *args, t_flag *flag)
{
	int	len;

	len = pf_strlen(args);
	if (args == NULL)
		len = 6;
	if (flag->poin && flag->prec < len)
		len = flag->prec;
	if (flag->widt && !flag->minu)
		print_stuff(flag->widt - len, flag, 1);
	if (args != NULL)
		printstr(args, flag);
	else
		printstr("(null)", flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - len, flag, 1);
	i++;
	return (i);
}

int	print_p(int i, va_list args, t_flag *flag)
{
	void	*ptr;
	int		n;

	ptr = va_arg(args, void *);
	n = len_num_hex((unsigned long int)ptr);
	if (flag->plus || flag->spce)
		n++;
	if (flag->prec > n)
		n = flag->prec;
	if (flag->widt && !flag->minu)
		print_stuff(flag->widt - n - 2, flag, 1);
	if (ptr == 0)
		printstr("0x0", flag);
	else
		putnbr_ptr((unsigned long int)ptr, "0123456789abcdef", flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - n - 2, flag, 1);
	i++;
	return (i);
}

int	print_id(int i, va_list args, t_flag *flag)
{
	int	n;
	int	num;

	num = va_arg(args, int);
	n = len_num(num);
	if (((flag->plus || flag->spce) && num >= 0) || num < 0)
		n++;
	if (num < 0 && flag->prec >= n)
		n = flag->prec + 1;
	if (flag->prec > n)
		n = flag->prec;
	if (flag->poin && flag->prec == 0 && num == 0)
		n = 0;
	printsymbol(num, n, flag);
	pf_putnbr(num, flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - n, flag, 1);
	return (++i);
}

int	print_u(int i, va_list args, t_flag *flag)
{
	unsigned int	num;
	int				n;

	num = va_arg(args, unsigned int);
	n = len_num(num);
	if (flag->plus || flag->spce)
		n++;
	if (flag->prec > n)
		n = flag->prec;
	if (flag->poin && flag->prec == 0 && num == 0)
		n = 0;
	if (flag->widt && !flag->minu)
		print_stuff(flag->widt - n, flag, 1);
	if (flag->plus)
		printchar('+', flag);
	if (flag->spce && !flag->plus)
		printchar(' ', flag);
	if (flag->prec > len_num(num))
		print_stuff(flag->prec - len_num(num), flag, 0);
	pf_putnbr(num, flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - n, flag, 1);
	i++;
	return (i);
}

/* Print_x is in Chrchecker due to normes */
