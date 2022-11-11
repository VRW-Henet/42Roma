#include "push_swap.h"

void	ps_micro_pull(t_struct *data, int size)
{
	if (data->ar_b[size] < data->ar_b[0])
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
	}
	else
		ps_push_a(data);
	if (data->size_a > 1)
		ps_swap_a(data);
	if (data->ar_b[size] < data->ar_b[0])
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
	}
	else
		ps_push_a(data);
	ps_swap_a(data);
}

void	ps_pull(t_struct *data, t_short *best)
{
	while (data->size_b != 0)
	{
		if (data->ar_b[0] > data->ar_b[data->size_b - 1])
			ps_rev_rotate_b(data);
		ps_instruction(data->ar_a, data->size_a, data, best);
		if (data->ar_a[0] > data->ar_b[0] && \
			(data->ar_a[data->size_a - 1] < data->ar_b[0] || \
			data->ar_a[0] == best->low_value))
			ps_minor_combo(data);
		else if ((data->ar_a[0] < data->ar_b[0] && \
			data->ar_a[1] > data->ar_b[0]) || \
			(data->ar_a[0] == best->end_value || \
			data->ar_a[1] == best->low_value))
			ps_major_combo(data);
		else
			ps_rotate_a(data);
	}	
}

void	ps_minor_combo(t_struct *data)
{
	while (data->ar_b[data->size_b - 1] < data->ar_b[0])
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
	}
	ps_push_a(data);
}

void	ps_major_combo(t_struct *data)
{
	while ((data->ar_b[data->size_b - 1] < data->ar_b[0]) \
	&& (data->ar_b[data->size_b - 1] > data->ar_a[0]))
	{
		ps_rev_rotate_b(data);
		ps_rotate_a(data);
		ps_push_a(data);
	}
	if (data->ar_b[data->size_b - 1] < data->ar_a[0])
		ps_minor_major_combo(data);
	else
	{
		ps_rotate_a(data);
		ps_push_a(data);
	}
}

void	ps_minor_major_combo(t_struct *data)
{
	int	temp;

	temp = data->ar_a[0];
	if (data->ar_b[data->size_b - 1] < data->ar_b[0] \
	&& data->ar_b[data->size_b - 1] < temp)
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
	}
}