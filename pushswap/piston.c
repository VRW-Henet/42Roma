#include "push_swap.h"

void	ps_ar_order(t_struct *data, t_short *best)
{
	int i;

	i = 0;
	while (data->size_a > 1)
	{
		if (data->ar_a[0] != best->low_value)
		{
			best->utility[i] = data->ar_a[0];
			ps_push_b(data);
			i++;
		}
        if (data->size_a > 1)
		    ps_rotate_a(data);
	}
    while (i > 0)
	{
        ps_find_big(best, i);
        ps_get_big(data, best, i);
        i--;
    }
}

void	ps_find_big(t_short *best, int i)
{
	best->nb = best->utility[i];
	while (i > 0)
	{
		if (best->nb > best->utility[i])
			best->nb = best->utility[i];
		i--;
	}
}

void    ps_get_big(t_struct *data, t_short *best, int i)
{
    int j;

    j = 0;
    while (j <= i)
    {
        while (data->ar_b[0] != best->nb)
        {
            ps_rotate_b(data);
            j++;
        }
        ps_push_a(data);
    }
    while (j > 0)
    {
        ps_rev_rotate_b(data);
        j--;
    }
}