/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:42:32 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 12:42:48 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_init_a(char *arg, int *size)
{
	char	**temp;
	int		*ar;
	int		i;

	temp = ft_split(arg, ' ');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (ps_filter(temp, i) != 1)
		ps_error("stack values error");
	ar = (int *) malloc (sizeof(int) * i);
	ps_mallok(ar);
	*size = i;
	i = 0;
	while (temp[i] != NULL)
	{
		ps_limit(temp[i]);
		ar[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (ar);
}

int	*ps_init_b(char **matrix, int size)
{
	int	*ar;
	int	i;

	ar = (int *) malloc (sizeof(int) * (size));
	ps_mallok(ar);
	i = 0;
	while (i < size)
	{
		ps_limit(matrix[i]);
		ar[i] = ft_atoi(matrix[i]);
		i++;
	}
	return (ar);
}
