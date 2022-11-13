#include "push_swap.h"

void	pullporcamadonna(t_struct *data, t_short *best, int i)
{
	while (i >= 0)
	{
		if (data->ar_b[0] < data->ar_a[0] && data->ar_a[0] == best->low_value)
			{
				ps_push_a(data);
				best->low_value = data->ar_a[0];
				i--;
			}
		if ((data->ar_a[0] < data->ar_b[0] && data->ar_a[1] > data->ar_b[0]) \
		|| (data->ar_a[0] < data->ar_b[0] && data->ar_a[0] == best->end_value))
		{
			if (data->ar_a[0] == best->end_value)
				best->end_value = data->ar_b[0];
			ps_rotate_a(data);
			ps_push_a(data);
			i--;
		}
		else
			ps_rotate_a(data);
	}
}

void	ps_pull_last_sequence(t_struct *data, t_short *best)
{
	int	i;

	i = 0;
	while (data->ar_b[i] < data->ar_b[i + 1])
		i++;
	ps_instruction(data->ar_a, data->size_a, data, best);
	pullporcamadonna(data, best, i);
}

