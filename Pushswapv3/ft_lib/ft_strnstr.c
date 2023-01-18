/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:01:32 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/17 14:04:39 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		while (*(haystack + i + c) == *(needle + c)
			&& *(haystack + i + c) && (i + c) < len && *(needle + c))
		{
			c++;
			if (*(needle + c) == 0)
				return ((char *)haystack + i);
		}
		i++;
		c = 0;
	}
	return (NULL);
}
