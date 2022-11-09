#include "push_swap.h"

int	*ps_mallocation(int *ar, int size)
{
	ar = (int *) malloc (sizeof (int) * (size));
	if(ar == NULL)
		ps_error("Malloc Failed");
	return (ar);
}

void	ps_deploy_memory(t_struct *data, t_short *best, int size)
{
	data->ar_a = ps_mallocation(data->ar_a, size);
	data->ar_b = ps_mallocation(data->ar_b, size);
	best->ar = ps_mallocation(best->ar, size);
	best->moves = ps_mallocation(best->moves, size);
	best->utility = ps_mallocation(best->utility, size);
} 

void	ps_reset_memory(t_struct *data, t_short *best)
{
	free(data->ar_a);
	free(data->ar_b);
	free(best->ar);
	free(best->moves);
}

void	ps_free_matrix(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
}
