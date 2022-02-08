/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:53:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/08 14:20:18 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "ft_printf.h"

void    flags_at_zero(t_flag *flags/* ,int io   RICORDATI DI AGGIUNGERE IL PARAMETRO IN GIRO PLS */)
{
    flag->hash = 0;
    flag->spce = 0;
    flag->plus = 0;
}

int ft_printf(const char *str, ...)
{
    int lenght;
    int i;
    t_flag  *flag;

    i = 0;
    flags = malloc(sizeof(t_flag));
    if (!flag)
        return (0);
    va_start(flag->arg, str);
    flags_at_zero(flag);
    
}
