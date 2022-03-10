/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:30:24 by dpadrini          #+#    #+#             */
/*   Updated: 2022/03/10 10:51:33 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = gnl_strlen(s1);
	len += gnl_strlen(s2);
	str = gnl_calloc((len + 1), sizeof(char));
	if (!str)
		return (str);
	while (s1[i] != 0)
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		*(char *)(ptr + i) = (unsigned char) 0;
		i++;
	}
	return (ptr);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			size_b;

	if (!s)
		return (NULL);
	if (len > gnl_strlen(s))
		len = gnl_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
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
