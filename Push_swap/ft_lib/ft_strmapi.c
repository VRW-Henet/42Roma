/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:05:39 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/24 13:50:54 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	if (!s || !f)
		return (NULL);
	i = 0;
	newstr = ft_strdup(s);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (newstr);
}
