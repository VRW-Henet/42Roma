#include "push_swap.h"

void	ps_rotate(int *ar, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		ps_error("size too small, can't rotate");
	i = 0;
	temp = ar[0];
	while (i < size - 1)
	{
		ar[i] = ar[i + 1];
		i++;
	}
	ar[i] = temp;
}

void	ps_rotate_a(t_struct *data)
{
	ft_printf("ra\n");
	ps_rotate(data->ar_a, data->size_a);
}

void	ps_rotate_b(t_struct *data)
{
	ft_printf("rb\n");
	ps_rotate(data->ar_b, data->size_b);
}

void	ps_rotate_r(t_struct *data)
{
	ft_printf("rr\n");
	ps_rotate(data->ar_a, data->size_a);
	ps_rotate(data->ar_b, data->size_b);
}
