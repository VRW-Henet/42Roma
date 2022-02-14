/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/14 15:02:15 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	convert(char *str, int i, t_flag *flag)
{
	while (str[i])
	{
		if (str[i] == 'c')
			print_sc(str, *flag, '0');
		else if (str[i] == 's')
			print_sc(str, *flag, '1');
		else if (str[i] == 'p')
			print_p(str, *flag);
		else if (str[i] == 'd')
			print_id(str, *flag, '0');
		else if (str[i] == 'i')
			print_id(str, *flag, '1');
		else if (str[i] == 'u')
			print_u(str, *flag);
		else if (str[i] == 'x')
			print_xX(str, *flag, '0');
		else if (str[i] == 'X')
			print_xX(str, *flag, '1');
		else if (str[i] == '%')
			ft_putchar_fd('%', 1);
		i++;
	}
}
