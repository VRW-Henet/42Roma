#include "push_swap.h"

void	ps_push_first_sequence(t_struct *data, t_short *best)
{
	int	size;
	int	flag;

	size = data->size_a - 1;
	flag = 0;
	while (flag != 1)
	{
		if(data->ar_a[0] > best->mid_value)
			ps_rotate_a(data);
		else
			flag = 1;
	}
	while (size >= 0)
	{
		if (data->ar_a[0] > data->ar_b[0])
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

void	ps_push_end_sequence(t_struct *data, t_short *best)
{	
	int	size;

	ps_wheel(data, best, best->end_value);
	ps_push_b(data);
	size = data->size_a - 1;
	while (size > 1)
	{
		if (data->ar_a[0] < data->ar_b[0])
			ps_push_b(data);
		else
			ps_rotate_a(data);
		size--;
	}
}

void	ps_exe_last_sequence(t_struct *data, t_short *best)
{
	int	size;
	int counter;

	size = data->size_a - 1;
	ft_printf("starting last sequence procedure\n");
	if (data->size_a > 3)
	{
		counter = part_two(data, best, 0, size);
	}
	ps_ar_order(data, best);
	ps_pull(data, counter, best);
}

int	part_two(t_struct *data, t_short *best, int counter, int size)
{
	int	size_flag;

	size_flag = size / 2;
	while (size > 0)
		{
			if (data->ar_a[0] == best->low_value)
				ps_rotate_a(data);
			else if ((data->ar_a[0] > data->ar_b[0] \
			&& data->ar_a[0] < best->mid_value) \
			|| (data->ar_a[0] > data->ar_b[0] && size < size_flag))
			{
				ps_push_b(data);
				counter++;
			}
			else
				ps_rotate_a(data);
			size--;
		}
	return (counter);
}