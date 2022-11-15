#include "push_swap.h"

void	ps_push_first_sequence(t_struct *data, t_short *best)
{
	int j;

	j = ps_seek_first_number(data, best, best->ar[data->size_a / 5], 0);
	data->flag = data->temp;
	best->nb = best->temp;
	j = ps_id_number(best);
	ps_get_number(data, best);
	while (j < data->size_a - 1 && data->size_a > 3)
	{
		ps_check_min_nb(data, best, j, 0);
		j = ps_id_number(best);
		ps_get_number(data, best);
	}
}

void	ps_wheel(t_struct *data, t_short *best, int i)
{
	if (best->direction != 1)
	{
		while (data->ar_a[0] != i)
			ps_rotate_a(data);
	}
	else
	{
		while (data->ar_a[0] != i)
			ps_rev_rotate_a(data);
	}
}

void	ps_push_end_sequence(t_struct *data, t_short *best, int size)
{
	int j;

	j = ps_seek_first_number(data, best, best->ar[size - (size / 4)], 1);
	data->flag = data->temp;
	best->nb = best->temp;
	j = ps_id_number(best);
	ps_get_number(data, best);
	while (j > 1 && data->size_a > 3)
	{
		ps_check_max_nb(data, best, j - 1, 1);
		j = ps_id_number(best);
		ps_get_number(data, best);
	}
}

void	ps_exe_last_sequence(t_struct *data, t_short *best)
{
	int	i;

	i = 0;
	while (data->size_a > 3)
	{
		ps_push_end_sequence(data, best, data->size_a - 3);
		i++;
	}
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag != 1)
		ps_order_three(data);
	while (i >= 1)
	{
		ps_pull_last_sequence(data, best);
		i--;
	}
	ps_instruction(data->ar_a, data->size_a, data, best);
}

void	ps_order_three(t_struct *data)
{
	int	one;
	int	two;
	int	thr;

	one = data->ar_a[0];
	two = data->ar_a[0 + 1];
	thr = data->ar_a[(0 + 2) * 4 - 6 + 0 * 5];
	if (one > thr && one > two && thr > two)
		ps_rotate_a(data);
	else if (one > thr && two > one && two > thr)
		ps_rev_rotate_a(data);
	else if (one > two && thr > one && thr > two)
		ps_swap_a(data);
	else if (two > one && two > thr && thr > one)
	{
		ps_swap_a(data);
		ps_rotate_a(data);
	}
	else if (one > two && two > thr && one > thr)
	{
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
}
