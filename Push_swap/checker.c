/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:32:25 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/06 12:32:41 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_checkmove(char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		return ;
	if (ft_strcmp(str, "pb\n") == 0)
		return ;
	if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		return ;
	if (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		return ;
	if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return ;
	if (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return ;
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		return ;
	if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		return ;
	ps_error("checked invalid moves");
}

void	ps_correct(t_struct *data, char *str)
{
	ps_checkmove(str);
	if (ft_strcmp(str, "pa\n") == 0)
		ps_push(data->ar_b, data->ar_a, &data->size_b, &data->size_a);
	if (ft_strcmp(str, "pb\n") == 0)
		ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
	if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		ps_shift(data->ar_a, data->size_a);
	if (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		ps_shift(data->ar_b, data->size_b);
	if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		ps_rev_shift(data->ar_a, data->size_a);
	if (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		ps_rev_shift(data->ar_b, data->size_b);
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		ps_swap(data->ar_a, data->ar_a + 1, data->size_a);
	if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		ps_swap(data->ar_b, data->ar_b + 1, data->size_b);
}

void	ps_control(t_struct *data)
{
	char	*str;

	str = get_next_line(0);
	while (ps_order(data->ar_a, data->size_a) == 0 || data->size_b != 0)
	{
		if (str == NULL)
			break ;
		ps_correct(data, str);
		free (str);
		str = get_next_line(0);
	}
	if (str != NULL)
		free(str);
	if (ps_order(data->ar_a, data->size_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_struct	data;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		data.ar_a = ps_init_b(argv[1], &data.size_a);
	else
	{
		argc -= 1;
		if (ps_filter(&argv[1], argc) == 0)
			ps_error("checker error, fix!");
		data.ar_a = ps_init_a(&argv[1], argc);
		data.size_a = argc;
	}
	if (ps_check_doubles(data.ar_a, data.size_a) == 0)
		ps_error("Checker found an invalid double number");
	data.ar_b = (int *) malloc (sizeof(int) * (int) data.size_a);
	data.size_b = 0;
	ps_control(&data);
	free(data.ar_a);
	free(data.ar_b);
	return (0);
}
