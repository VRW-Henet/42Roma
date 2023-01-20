/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:46 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:46 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_initialization(t_struct *data, t_short *best, int argc, char **argv)
{
	if (argc == 2)
		ps_init_single(argv[1], data, best);
	else
		ps_init(argv, data, best, argc - 1);
	data->og_size = data->size_a;
}

void	ps_micro_engine(t_struct *data, t_short *best)
{
	if (data->size_a == 2)
	{
		if (data->ar_a[0] > data->ar_a[1])
			ps_swap_a(data);
	}
	else if (data->size_a == 3)
		ps_order_three(data);
	else if (data->size_a <= 7)
	{
		while (data->size_a != 3)
			ps_push_b(data);
		ps_order_three(data);
		ps_pull(data, best);
	}
}

void	ps_engine(t_struct *data, t_short *best)
{
	ps_push_first_sequence(data, best);
	ps_exe_last_sequence(data, best);
	ps_order_three(data);
	ps_pull(data, best);
}

int	main(int argc, char **argv)
{
	t_struct	*data;
	t_short		*best;

	if (argc <= 1)
		return (-1);
	data = (t_struct *) malloc(sizeof(t_struct));
	best = (t_short *) malloc(sizeof(t_short));
	if (!data || !best)
		return (1);
	ps_initialization(data, best, argc, argv);
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
	data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
	{
		ps_reset_memory(data, best);
		return (0);
	}
	if (data->size_a <= 7)
		ps_micro_engine(data, best);
	else
		ps_engine(data, best);
	ps_reset_memory(data, best);
	return (0);
}
