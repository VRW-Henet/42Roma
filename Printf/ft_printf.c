/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:53:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/14 14:32:21 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *str, ...)
{
    int     i;
    char    *s;
    t_flag  *flag;

    i = 0;
    s = (char *) str;
    va_start(args, str);
    flag = malloc(sizeof(t_flag));
    if (!flag)
        return (0);
    flags_at_zero(flag, 0);
    i = check_n_print(s, i, flag);
    i = look_for_flags(s, i, flag);
    }
    return (flag->leng);
}
