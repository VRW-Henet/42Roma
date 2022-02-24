/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:53:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/23 23:30:30 by dpadrini         ###   ########.fr       */
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
	flags_at_zero(flag, 0);
	while (s[i])
	{
		i = check_n_print(s, i, flag);
		if (!s[i])
			break ;
		i = look_for_flags(s, ++i, flag);
		i = check_for_conversions(s, i, flag, args);
		flags_at_zero(flag, 1);
	}
	va_end(args);
	free(flag);
	return (flag->leng);
}
