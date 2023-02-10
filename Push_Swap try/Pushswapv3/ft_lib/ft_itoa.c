/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:18:53 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/24 11:04:04 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checklen(int n)
{
	unsigned int	nbr;
	int				len;
	int				m;

	m = 1;
	if (n < 0)
	{
		nbr = n * -1;
		len = 2;
	}
	else
	{
		len = 1;
		nbr = n;
	}
	while ((nbr / m) > 9)
	{
		m *= 10;
		len++;
	}
	return (len + 1);
}

int	makedivider(int len, int n)
{
	int	m;

	m = 1;
	if (n < 0)
		len -= 3;
	else
		len -= 2;
	while (len > 0)
	{
		m *= 10;
		len--;
	}
	return (m);
}

unsigned int	checksign(int n)
{	
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	int				m;
	unsigned int	nbr;
	char			*str;
	int				i;
	int				len;

	i = -1;
	m = 1;
	len = checklen(n);
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	m = makedivider(len, n);
	if (n < 0)
		str[++i] = '-';
	nbr = checksign(n);
	while (m > 0)
	{
		str[++i] = ((nbr / m) % 10) + '0';
		m /= 10;
	}
	str[++i] = '\0';
	return (str);
}
