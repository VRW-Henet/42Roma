#include "push_swap.h"

void	ps_swap(int *a, int *b, int size)
{
	int	temp;

	if (size <= 1)
		ps_error("size too smöl, swap aborted");
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ps_swap_ab(int *ar, int size, char *ab)
{
	ft_printf("s%c\n", ab);
	ps_swap(ar, ar + 1, size);
}

void	ps_swap_s(int *ar_a, int *ar_b, int size)
{
	ft_printf("ss\n");
	ps_swap(ar_a, ar_a + 1, size);
	ps_swap(ar_b, ar_b + 1, size);
}
