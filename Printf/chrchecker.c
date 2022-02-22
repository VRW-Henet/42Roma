/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/22 11:06:22 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(char *str, int i, t_flag *flag)
{	
	if (str[i] == '-')
		flag->minu = 1;
	else if (str[i] == '0')
		flag->zero = 1;
	else if (str[i] == '.')
	{
		flag->poin = 1;
		while (pf_isdigit(str[i++]))
		{
			flag->prec = (flag->prec * 10) + (str[i] - 48);
			flag->leng++;
		}
	}
	else if (str[i] == '#')
		flag->hash = 1;
	else if (str[i] == ' ')
		flag->spce = 1;
	else if (str[i] == '+')
		flag->plus = 1;
	return (i);
}

int	check_for_conversions(char *str, int i, t_flag *flag, va_list args)
{
	if (str[i] == 'c')
		return (print_c(i, args, flag));
	else if (str[i] == 's')
		return (print_s(i, va_arg(args, char *), flag));
	else if (str[i] == 'p')
		return (print_p(i, args, flag));
	else if (str[i] == 'd' || str[i] == 'i')
		return (print_id(i, args, flag));
	else if (str[i] == 'u')
		return (print_u(i, args, flag));
	else if (str[i] == 'x' || str[i] == 'X')
		return (print_x(str, i, args, flag));
	else if (str[i] == '%')
	{
		printchar('%', flag);
		i++;
		return (i);
	}
	return (i);
}

char	*pf_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while ((*s != '\0') && (*s != ch))
	{
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return ((char *) NULL);
}

/* Right from conversions */
int	print_x(char *str, int i, va_list args, t_flag *flag)
{
	long long int	num;
	int				n;

	num = (long long int)va_arg(args, unsigned int);
	n = len_num_hex(num);
	if (((flag->plus || flag->spce) && num >= 0) || num < 0)
		n++;
	if (flag->prec > n)
		n = flag->prec;
	if (num < 0 && flag->prec >= n)
		n = flag->prec + 1;
	if (flag->poin && flag->prec == 0 && num == 0)
		n = 0;
	print_hex(str, num, n, flag);
	pf_putnbr_hex(*str, num, flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - n, flag, 1);
	return (i++);
}
