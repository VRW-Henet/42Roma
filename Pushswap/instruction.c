#include "pushswap.h"

void	ps_instruction(int *ar, int size, t_struct *data, t_short *best)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ps_ar_copy(data, best, size, ar);
	ps_order(best, size);
	while (i < size)
	{
		j = 0;
		while (best->ar[i] != ar[j] && j < size)
			j++;
		best->moves[i] = j;
		i++;
	}
	ps_set_pivot(data, best);
}
