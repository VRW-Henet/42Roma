/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:41 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/17 11:40:05 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	c = dstlen;
	if (dstsize > 0 && dstlen < dstsize - 1)
	{
		while ((dstlen + i) < (dstsize - 1) && src[i])
		{
			dst[c] = src[i];
			i++;
			c++;
		}
		dst[c] = 0;
	}
	if (dstlen >= dstsize)
	{
		dstlen = dstsize;
	}
	return (dstlen + srclen);
}
