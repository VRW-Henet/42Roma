#include "Push_swap.h"

void	ps_engine(t_struct data, t_short best)
{
	ps_push_first_sequence(&data, &best);
	ps_seek_end(&data, &best);
	ps_push_end_sequence(&data, &best);
}

void	ps_push_first_sequence(t_struct data, t_short best)
{
	int	size;
	int	size_flag;

	size = data.size_a;
	size_flag = size / 2;
	while (size > 0)
	{
		if ((data.ar_a[0] > data.ar_b[0] && data.ar_a[0] < best.mid_value) \
		|| (data.ar_a[0] > data.ar_b[0] && size < size_flag))
			ps_push_b(&data);
		else
			ps_rotate_a(&data);
		size--;
	}
}

void	ps_seek_end(t_struct data, t_short best)
{
	if (best.direction == 0)
	{
		while (ar_a[0] != best.end_value)
			ps_rotate_a(&data);
	}
	else
	{
		while (ar_a[0] != best.end_value)
			ps_rev_rotate_a(&data);
	}
	ps_push_b(&data);
}

void	ps_push_end_sequence(t_struct data, t_short best)
{
	int	size;
	int	size_flag;
	int	i;

	size = data.size_a;
	size_flag = size / 2;
	i = 0;
	while (size > 0)
	{
		if ((data.ar_a[0] < data.ar_b[0] && data.ar_a[0] > best.mid_value) \
		|| (data.ar_a[0] < data.ar_b[0] && size < size_flag))
		{
			ps_push_b(&data);
			i++;
		}
		else
			ps_rotate_a(&data);
		size--;
	}
	data->high_values_b = i;
}
