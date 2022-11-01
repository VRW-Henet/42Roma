#include "Push_swap.h"

int main(int argc, char **argv)
{
	t_struct	data;
	t_short		best;

	if (argc <= 1)
		ps_error("main01\nInvalid Input, add more arguments");
	if (argc == 2)
		ps_init_single(&argv, &data);
	else 
		ps_init(&argv, &data);
	ps_seek_for_doubles(data.ar_a, data.size_a);
	ps_instruction(data.ar_a, data.size_a, &best);
	ps_set_pivot(&data, &best);
	ps_engine(&data, &best);
	return (data.ar_a);
}

void	*ps_instruction(int *ar, int size, t_short best)
{
	int	i;
	int	j;

	i = 0;
	best.ar = ps_ar_copy(ar, size);
	ps_order(best, size);
	if (best.sort_flag = 1)
		ps_error("The values are already in sequence.")
	while (i < size)
	{
		j = 0;
		while (best.ar[i] != ar[j])
			j++;
		best->moves[i] = j;
		i++;
	}
}