/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:17 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:17 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_init_single(char *ar, t_struct *data, t_short *best)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_split(ar, ' ');
	while (values[i])
		i++;
	ps_deploy_memory(data, best, i);
	i = 0;
	while (values[i] != NULL)
	{
		ps_parse(data, best, values[i]);
		data->ar_a[i] = ft_atoi(values[i]);
		i++;
	}
	data->size_a = i;
	data->size_b = 0;
	ps_free_matrix(values, i);
}

void	ps_init(char **ar, t_struct *data, t_short *best, int size)
{
	int	i;

	i = 0;
	ps_deploy_memory(data, best, size);
	while (i < size)
	{
		ps_parse(data, best, ar[i + 1]);
		data->ar_a[i] = ft_atoi(ar[i + 1]);
		i++;
	}
	data->size_a = i;
	data->size_b = 0;
}

void	ps_parse(t_struct *data, t_short *best, char *subject)
{
	int	i;

	i = 0;
	while (subject[i] != 0)
	{
		if (subject[i] == '-' || subject[i] == '+')
			i++;
		else if (ft_isdigit(subject[i]))
		{
			while (ft_isdigit(subject[i]))
				i++;
			ps_limit(data, best, subject);
		}
		else
			ps_error(data, best);
	}
}

void	ps_limit(t_struct *data, t_short *best, char *number)
{
	long long int	nb;
	int				i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	nb = 0;
	while (number[i] != '\0')
	{
		nb *= 10;
		nb += number[i] - '0';
		i++;
	}
	if (nb > 2147483647)
		ps_error(data, best);
}

void	ps_set_pivot(t_struct *data, t_short *best)
{
	int	size;

	size = data->size_a - 1;
	best->low_value = best->ar[0];
	best->lowmid_value = best->ar[size / 3];
	best->highmid_value = best->ar[(size / 3) * 2];
	best->end_value = best->ar[size];
	if (best->moves[size] > ((size / 2) + 1))
		best->direction = 1;
	else
		best->direction = 0;
}
