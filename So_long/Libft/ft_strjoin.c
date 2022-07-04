/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:33:50 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/28 17:25:45 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c])
		str[i++] = s2[c++];
	str[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2, int f1, int f2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c])
		str[i++] = s2[c++];
	str[i] = '\0';
	if (f1)
		free(s1);
	if (f2)
		free(s2);
	return (str);
}
