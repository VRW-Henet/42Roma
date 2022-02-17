/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:56:45 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/15 10:57:53 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_flag
{
	char	type;
	int		minu;
	int		zero;
	int		plus;
	int		hash;
	int		spce;
	int		poin;
	int		prec;
	int		widt;
	int		leng;
}	t_flag;



#endif