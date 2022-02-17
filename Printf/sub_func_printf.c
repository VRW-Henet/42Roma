/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:51 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/17 14:55:32 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

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

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
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
			break;
		{
        if (str[size] == '%')
        	size++;
		size++;
	}
	while (i <= size && str[i])
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
		if (flag->minu = 1 || flag->poin = 1)
			flag->zero = 0;
		while (ft_isdigit(str[i]))
		{
			flag->widt = (flag->widt * 10) + (str[i] - 48);
			i++;
		}
		i++;
		flag->type = *s;
	}
	return (i);
}

void	ft_putnbr_hex(char ch, long long int num, t_flag *flag)
{
	char	result[18];
	int		i;
	char	*base;

	if (flag->poin && flag->prec == 0 && num == 0)
		return ;
	i = 1;
	if (num == 0)
		printchar('0', flag);
	if (ch == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (num)
	{
		result[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	while (i)
	{
		printchar(result[i], flag);
		i--;
	}
}
