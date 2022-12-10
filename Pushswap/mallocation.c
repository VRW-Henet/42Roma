#include "pushswap.h"

int	*ps_mallocation(t_struct *data, t_short *best, int size)
{
	int *ar;

	ar = (int *) malloc (sizeof (int) * (size));
	if(ar == NULL)
		ps_error(data, best);
	return (ar);
}

void	ps_deploy_memory(t_struct *data, t_short *best, int size)
{
	data->ar_a = ps_mallocation(data, best, size);
	data->ar_b = ps_mallocation(data, best, size);
	best->ar = ps_mallocation(data, best, size);
	best->moves = ps_mallocation(data, best, size);
	best->mem = 1;
} 

void	ps_reset_memory(t_struct *data, t_short *best)
{
	if (best->mem == 1)
	{
		free(data->ar_a);
		free(data->ar_b);
		free(best->ar);
		free(best->moves);
	}
	free(data);
	free(best);}

void	ps_free_matrix(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
}
