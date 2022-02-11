/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:51 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/10 14:45:43 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    flags_at_zero(t_flag *flag/* ,int io - IN CASO RICORDATI DI AGGIUNGERE IL PARAMETRO IN GIRO PLS */)
{
	flag->minu = 0;
	flag->zero = 0;
	flag->plus = 0;
    flag->hash = 0;
    flag->spce = 0;
    flag->poin = 0;
	flag->prec = 0;
	flag->widt = 0;
	flag->leng = 0;
}

int	ft_sortchr(char *str, int i, t_flag *flag)
{
	if (ft_strchr("-0.# +", str[i]))
		checkflags(str, i + 1, *flag);
	else if (ft_strchr("csp%diuxX", str[i]))
		convert(str, i, *flag);
	return (i);
}


