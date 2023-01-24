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
	if (data->size_b != 0)
	{
		ft_printf("%d, %d\n", data->size_a, data->size_b);
		ft_printf("KO\n");
		return ;
	}
	ft_printf("OK\n");
}

int	ps_execute_moves(t_struct *data, char *moves)
{
	if (ft_strcmp(moves, "pa\n") == 0)
		ps_push_a(data);	
	else if (ft_strcmp(moves, "pb\n") == 0)
		ps_push_b(data);
	else if (ft_strcmp(moves, "rra\n") == 0)
		ps_rev_rotate_a(data);
	else if (ft_strcmp(moves, "rrb\n") == 0)
		ps_rev_rotate_b(data);
	else if (ft_strcmp(moves, "rrr\n") == 0)
		ps_rev_rotate_r(data);
	else if (ft_strcmp(moves, "sa\n") == 0)
		ps_swap_a(data);
	else if (ft_strcmp(moves, "sb\n") == 0)
		ps_swap_b(data);
	else if (ft_strcmp(moves, "ss\n") == 0)
		ps_swap_s(data);
	else if (ft_strcmp(moves, "ra\n") == 0)
		ps_rotate_a(data);
	else if (ft_strcmp(moves, "rb\n") == 0)
		ps_rotate_b(data);
	else if (ft_strcmp(moves, "rr\n") == 0)
		ps_rotate_r(data);
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
		if (moves == NULL)
			break ;
		ps_execute_moves(data, moves);
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
	data->checker = 1;
	data->og_size = data->size_a;
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
		data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
		return (0);
	ps_check_moves(data);
	ps_reset_memory(data, best);
	return (0);
}