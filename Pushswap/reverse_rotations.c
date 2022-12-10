#include "pushswap.h"

void	ps_rev_rotate(int *ar, int size)
{
	int	temp;
	
	size -= 1;
	temp = ar[size];
	while (size > 0)
	{
		ar[size] = ar[size - 1];
		size--;
	}
	ar[size] = temp;
}

void	ps_rev_rotate_a(t_struct *data)
{
	if (data->size_a <= 1)
		return ;
	ft_printf("rra\n");
	ps_rev_rotate(data->ar_a, data->size_a);
}

void	ps_rev_rotate_b(t_struct *data)
{
	if (data->size_b <= 1)
		return ;
	ft_printf("rrb\n");
	ps_rev_rotate(data->ar_b, data->size_b);
}

void	ps_rev_rotate_r(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ft_printf("rrr\n");
	ps_rev_rotate(data->ar_a, data->size_a);
	ps_rev_rotate(data->ar_b, data->size_b);
}

void	ps_rrr(t_struct *data)
{
	if (data->size_a <= 1 || data->size_b <= 1)
		return ;
	ps_rev_rotate(data->ar_a, data->size_a);
	ps_rev_rotate(data->ar_b, data->size_b);
}
