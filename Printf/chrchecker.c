/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/20 12:34:25 by dpadrini         ###   ########.fr       */
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
		while (ft_isdigit(str[i++]))
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
	if (str[i] == 'c' || str[i] == 's')
		i = print_sc(str, i, args, flag);
	else if (str[i] == 'p')
		i = print_p(i, args, flag);
	else if (str[i] == 'd' || str[i] == 'i')
		i = print_id(i, args, flag);
	else if (str[i] == 'u')
		i = print_u(i, args, flag);
	else if (str[i] == 'x' || str[i] == 'X')
		i = print_x(str, i, args, flag);
	else if (str[i] == '%')
	{
		printchar('%', flag);
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
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