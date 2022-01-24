/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:31:23 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/18 21:47:30 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		bgn;
	char	*s2;

	end = ft_strlen(s1);
	bgn = 0;
	i = 0;
	while (s1[bgn] && ft_strchr(set, s1[bgn]))
		bgn++;
	while (end > bgn && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = (char *)malloc(end - bgn + 1);
	if (!s2)
		return (NULL);
	while (bgn < end)
	{
		s2[i] = s1[bgn];
		bgn++;
		i++;
	}
	s2[i] = 0;
	return (s2);
}
