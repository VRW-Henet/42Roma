/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:41:34 by dpadrini          #+#    #+#             */
/*   Updated: 2022/02/14 11:47:12 by dpadrini         ###   ########.fr       */
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