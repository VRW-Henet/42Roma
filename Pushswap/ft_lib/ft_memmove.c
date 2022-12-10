/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:56:53 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/27 12:52:49 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstc;
	char	*srcc;

	i = 0;
	dstc = (char *)dst;
	srcc = (char *)src;
	if (!dstc && !srcc)
		return (NULL);
	if (dstc > srcc)
	{
		while (len-- > 0)
			dstc[len] = srcc[len];
	}
	else
	{
		while (i < len)
		{
			dstc[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
