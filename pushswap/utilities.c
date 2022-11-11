#include "push_swap.h"

void	ps_error(t_struct *data, t_short *best, char *message)
{
	ft_printf("ERROR:%s\n", message);
	ps_reset_memory(data, best);
	exit(1);
}

void	ps_seek_for_doubles(t_struct *data, t_short *best, int *ar, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (ar[j] != 0)
		{
			if (ar[i] == ar[j])
				ps_error(data, best, "seek_for_doubles01\nNumber detected twice");
			j++;
		}
		i++;
	}
}

void	ps_ar_copy(t_short *best, int size, int *ar)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		best->ar[i] = ar[i];
		i++;
	}
}

void	ps_order(t_short *best, int size)
{
	int	i;
	int	j;
	int complete;

	i = 0;
	best->sort_flag = 1;
	while (complete != 1)
	{
		complete = 1;
		while (i < size - 1)
		{
			j = i;
			while (j < size - 1)
			{
				j++;
				if (best->ar[i] > best->ar[j])
				{
					ps_swap_order(best, i, j);
					complete = 0;
					best->sort_flag = 0;
					i = 0;
					j = 0;
				}
			}
			i++;
		}
	}
}

void	ps_swap_order(t_short *best, int i, int j)
{
	best->swapper = best->ar[i];
	best->ar[i] = best->ar[j];
	best->ar[j] = best->swapper;
}