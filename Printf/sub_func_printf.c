/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:51 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/14 15:02:14 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    flags_at_zero(t_flag *flag, int io)
{	
	flag->type = '\0';
	flag->minu = 0;
	flag->zero = 0;
	flag->plus = 0;
    flag->hash = 0;
    flag->spce = 0;
    flag->poin = 0;
	flag->prec = 0;
	flag->widt = 0;
	if(io == 0)
		flag->leng = 0;
}

void	printchar(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->leng++;
}

int	check_n_print(char *str, size_t size, t_flag *flag)
{
	int	i;

	i = 0;
	while (str[size])
    {
        if (str[size] == '%' && str[size + 1] != '%')
		{
            size++;
			return (size);
		{
        if (str[size] == '%')
        	size++;
		size++;
	}
	while (i < size && str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			printchar('%', flag);
			i++;
		}
		if (str[i] != '%')
			printchar(str[i], flag);
		i++;
	}
	return (size);
}

int	look_for_flags(char *str, int i, t_flag *flag)
{
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		i = check_flags(str, i, flag);
		if (ft_isdigit(str[i]) && flag->poin = 1)

	}
}