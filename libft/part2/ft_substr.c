/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:49:57 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/29 15:47:56 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			size_b;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (ft_calloc(1, 1));
	i = 0;
	size_b = 0;
	while (s[i] && i < start)
		i++;
	while (s[i] && size_b < len)
	{
		str[size_b] = s[i];
		i++;
		size_b++;
	}
	str[size_b] = '\0';
	return (str);
}
