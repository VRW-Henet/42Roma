#include "Push_swap.h"

void	ps_error(char *message)
{
	ft_printf("ERROR:%s\n", message);
	exit(1);
}

void	ps_seek_for_doubles(int *ar, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (ar[j] != NULL)
		{
			if (ar[i] == ar[j])
				ps_error("seek_for_doubles01\nNumber detected twice");
			j++;
		}
		i++;
	}
}

int	*ps_ar_copy(int *ar, int size)
{
	int	*copy;
	int	i;

	i = 0;
	while (ar)
	{
		copy[i] = ar[i];
		i++;
	}
	return (copy);
}

void	*ps_order(t_short best, int size)
{
	int	i;
	int	j;
	int complete;

	i = 0;
	best->sort_flag = 1;
	while (complete != 1)
	{
		complete = 1;
		while (i < 0)
		{
			j = i;
			while (j < size)
			{
				if (best.ar[i] < best.ar[j])
				{
					ps_swap(best, i, j);
					complete = 0;
					best->sort_flag = 1;
				}
				j++;
			}
			i++;
		}
	}
}

void	ps_swap(t_short best, int i, int j)
{
	int swap;

	swap = 0;

	swap = best.ar[i];
	best.ar[i] = best.ar[j];
	best.ar[j] = best.ar[i];
}