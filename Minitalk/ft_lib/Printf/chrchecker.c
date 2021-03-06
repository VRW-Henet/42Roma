/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/24 04:39:42 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_for_conversions(char *str, int i, t_flag *flag, va_list args)
{
	if (str[i] == 'c')
		return (print_c(i, va_arg(args, int), flag));
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
	long long	num;
	int			n;

	num = (long long)va_arg(args, unsigned int);
	n = len_num_hex(num);
	if (((flag->plus || flag->spce) && num >= 0) || num < 0)
		n++;
	if (flag->prec > n)
		n = flag->prec;
	if (num < 0 && flag->prec >= n)
		n = flag->prec + 1;
	if (flag->poin && flag->prec == 0 && num == 0)
		n = 0;
	print_hex(str[i], num, n, flag);
	pf_putnbr_hex(str[i], num, flag);
	if (flag->widt && flag->minu)
		print_stuff(flag->widt - n, flag, 1);
	i++;
	return (i);
}
