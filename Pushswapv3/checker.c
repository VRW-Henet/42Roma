/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:18:00 by dpadrini          #+#    #+#             */
/*   Updated: 2022/12/10 16:18:00 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_control(char *moves)
{
	if (moves == NULL)
		return (0);
	ft_printf("Error\n");
	return (0);
}

void	ps_check_final(t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->ar_a[i] > data->ar_a[i + 1])
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
}

int	ps_execute_moves(t_struct *data, char *moves)
{
	if (ft_strcmp("pa\n", moves))
		ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
	else if (ft_strcmp("pb\n", moves))
		ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
	else if (ft_strcmp("rra\n", moves))
		ps_rev_rotate(data->ar_a, data->size_a);
	else if (ft_strcmp("rrb\n", moves))
		ps_rev_rotate(data->ar_b, data->size_b);
	else if (ft_strcmp("rrr\n", moves))
		ps_rrr(data);
	else if (ft_strcmp("sa\n", moves))
		ps_swap(&data->ar_a[0], &data->ar_a[1]);
	else if (ft_strcmp("sb\n", moves))
		ps_swap(&data->ar_b[0], &data->ar_b[1]);
	else if (ft_strcmp("ss\n", moves))
		ps_ss(data);
	else if (ft_strcmp("ra\n", moves))
		ps_rotate(data->ar_a, data->size_a);
	else if (ft_strcmp("rb\n", moves))
		ps_rotate(data->ar_b, data->size_b);
	else if (ft_strcmp("rr\n", moves))
		ps_rr(data);
	else
		return (ps_control(moves));
	return (1);
}

void	ps_check_moves(t_struct *data)
{
	char	*moves;

	moves = get_next_line(0);
	while (1)
	{
		if (moves == NULL || !(ps_execute_moves(data, moves)))
			break ;
		free(moves);
		moves = get_next_line(0);
	}
	free(moves);
	ps_check_final(data);
}

int	main(int argc, char **argv)
{
	char		*str;
	t_struct	*data;
	t_short		*best;

	str = NULL;
	data = (t_struct *) malloc(sizeof(t_struct));
	best = (t_short *) malloc(sizeof(t_short));
	if (argc < 2)
		return (-1);
	if (argc == 2)
		ps_init_single(argv[1], data, best);
	else
		ps_init(argv, data, best, argc - 1);
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
		data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
		return (0);
	ps_check_moves(data);
	ps_reset_memory(data, best);
	return (0);
}
