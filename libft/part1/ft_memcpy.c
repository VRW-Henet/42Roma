/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:23:26 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/15 16:41:49 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst)
	{
		return (NULL);
	}
	while (n > 0)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
		n--;
	}
	return (dst);
}
