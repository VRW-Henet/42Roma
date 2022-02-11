/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/10 14:55:01 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkflags(char *str, int i, t_flag *flags)
{
	while (str[i])
	{
		if (str[i] == '-')
			flag->minu = 1;
		else if (str[i] == '0')
			flag->zero = 1;
		else if (str[i] == '.')
			flag->poin = 1;
			while (ft_isdigit(str[i + 1]))
				flag->prec = (flag->prec * 10) + (str[i] - 48);
				i++;
		else if (str[i] == '#')
			flag->hash = 1;
		else if (str[i] == ' ')
			flag->spce = 1;
		else if (str[i] == '+')
			flag->plus = 1;
		i++;
		else if (ft_isdigit(str[i]))
			flag->widt = (flag->widt * 10) + (str[i] - 48)
	}
	return (i);
}

void	convert(char *str, int i, t_flag *flag)
{
	while (str[i])
	{
		if (str[i] == 'c')
			print_sc(str, *flag, 'c');
		else if (str[i] == 's')
			print_sc(str, *flag, 's');
		else if (str[i] == 'p')
			print_p(str, *flag);
		else if (str[i] == 'd')
			print_id(str, *flag, 'd');
		else if (str[i] == 'i')
			print_id(str, *flag, 'i');
		else if (str[i] == 'u')
			print_u(str, *flag);
		else if (str[i] == 'x')
			print_xX(str, *flag, 'x');
		else if (str[i] == 'X')
			print_xX(str, *flag, 'X');
		else if (str[i] == '%')
			print_per(str, *flag);
	}
}