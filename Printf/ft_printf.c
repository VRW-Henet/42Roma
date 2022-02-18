/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:53:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/18 11:51:03 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	char	*s;
	t_flag	*flag;

	i = 0;
	s = (char *) str;
	va_start(args, str);
	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (0);
	while (s[i])
	{
		flags_at_zero(flag, 0);
		i = check_n_print(s, i, flag);
		i = look_for_flags(s, i, flag) + 1;
		i = check_for_conversions(s, i, flag);
		flags_at_zero(flag, 1);
	}
	va_end(args);
	free(flag);
	return (flag->leng);
}
