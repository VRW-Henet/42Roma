#include "push_swap.h"

void	ps_push_first_sequence(t_struct *data, t_short *best)
{
	int	size;

	size = data->size_a - 1;
	while (data->ar_a[0] != best->nb)
	{
		if (best->nb_dir == 1)
			ps_rev_rotate_a(data);
		else
			ps_rotate_a(data);
	}
	while (size >= 0)
	{
		if (data->ar_a[0] > data->ar_b[0] && \
		(data->ar_a[0] < best->mid_value || size < data->size_a / 2))
			ps_push_b(data);
		else
			ps_rotate_a(data);
		size--;
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
	ps_instruction(data->ar_a, data->size_a, data, best);
	ps_wheel(data, best, best->end_value);
	ps_push_b(data);
	size--;
	while (data->ar_a[0] != best->nb)
	{
		if (best->nb_dir == 1)
			ps_rev_rotate_a(data);
		else
			ps_rotate_a(data);
	}
	while (size > 1 && data->size_a > 1)
	{
		if (data->ar_a[0] < data->ar_b[0] && \
		(data->ar_a[0] > best->mid_value || size < data->size_a / 2))
			ps_push_b(data);
		else
			ps_rotate_a(data);
		size--;
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
	ps_order_three(data);
	while (i > 1)
	{
		ps_pull_last_sequence(data, best);
		i--;
	}
	ps_instruction(data->ar_a, data->size_a, data, best);
	while (data->ar_a[0] != best->low_value)
	{
		if (best->moves[0] < (((data->size_a - 1) / 2) + 1))
			ps_rotate_a(data);
		else
			ps_rev_rotate_a(data);
	}
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
