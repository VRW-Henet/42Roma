/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/18 12:41:18 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(char *str, int i, t_flag *flags)
{	
	if (str[i] == '-')
		flag->minu = 1;
	else if (str[i] == '0')
		flag->zero = 1;
	else if (str[i] == '.')
	{
		flag->poin = 1;
		while (ft_isdigit(str[i + 1]))
		{
			flag->prec = (flag->prec * 10) + (str[i] - 48);
			flag->leng++;
			i++;
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

int	check_for_conversions(char *str, int i, t_flag *flag)
{
	if (str[i] == 'c' || str[i] == 's')
		i = print_sc(str, i, args, flag);
	else if (str[i] == 'p')
		i = print_p(str, i, args, flag);
	else if (str[i] == 'd' || str[i] == 'i')
		i = print_id(str, i, args, flag);
	else if (str[i] == 'u')
		i = print_u(str, i, args, flag);
	else if (str[i] == 'x' || str[i] == 'X')
		i = print_x(str, i, args, flag);
	else if (str[i] == '%')
	{
		printchar('%', flag)
		i++;
	}
	return (i);
}
