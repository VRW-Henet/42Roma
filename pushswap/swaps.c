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

void	ps_swap_a(t_struct *data)
{
	ft_printf("sa\n");
	ps_swap(&data->ar_a[0], &data->ar_a[1], data->size_a);
}

void	ps_swap_b(t_struct *data)
{
	ft_printf("sb\n");
	ps_swap(&data->ar_b[0], &data->ar_b[1], data->size_b);
}

void	ps_swap_s(t_struct *data)
{
	ft_printf("ss\n");
	ps_swap(&data->ar_a[0], &data->ar_a[1], data->size_a);
	ps_swap(&data->ar_b[0], &data->ar_b[1], data->size_b);
}
