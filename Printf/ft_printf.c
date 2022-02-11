/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:53:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/10 14:45:48 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *str, ...)
{
    int i;
    int lenght;
    t_flag  *flag;

    i = 0;
    flag = malloc(sizeof(t_flag));
    if (!flag)
        return (0);
    va_start(flag->arg, str);
    flags_at_zero(flag);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i = ft_sortchr(str, i + 1, *flag);
            
        }
        else
        {
            lenght += write(1, str[i], 1);
        }
        i++;
    }
    return (lenght);
}
