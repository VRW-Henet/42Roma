#include "push_swap.h"

int	ps_fake_first_push(t_struct *data, t_short *best, int size)
{
	int	nb;
	int	i;

	nb = best->ar[0];
	i = 0;
	while (size > 0)
	{
		if (best->ar[0] > nb && \
		(best->ar[0] < best->mid_value || size < data->size_a / 2))
		{
			i++;
			nb = best->ar[0];
			ps_rotate(best->ar, data->size_a);
		}
		else
			ps_rotate(best->ar, data->size_a);
		size--;
	}
	return (i);
}

int	ps_fake_end_push(t_struct *data, t_short *best, int size)
{
	int	nb;
	int	i;

	nb = best->ar[0];
	i = 0;
	while (size > 1 && data->size_a > 1)
	{
		if (best->ar[0] < nb && \
		(best->ar[0] > best->mid_value || size < data->size_a / 2))
		{
			i++;
			nb = best->ar[0];
			ps_rotate(best->ar, data->size_a);
		}
		else
			ps_rotate(best->ar, data->size_a);
		size--;
	}
	return (i);
}

void	ps_longest_sequence(t_struct *data, t_short *best, int size)
{
	int	i;
	int j;

	j = 1;
	while (size > 0)
	{
		if (data->flag == 0)
			i = ps_fake_first_push(data, best, data->size_a);
		else
			i = ps_fake_end_push(data, best, data->size_a);
		if(i > j)
		{
			j = i;
			best->nb = best->ar[0];
			if (size < (data->size_a / 2) - 1)
				best->nb_dir = 1;
		}
		ps_rotate(best->ar, data->size_a);
		size--;
	}
}
