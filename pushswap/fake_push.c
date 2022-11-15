#include "push_swap.h"

int	ps_seek_first_number(t_struct *data, t_short *best, int x, int flag)
{
	int	i;
	int j;

	i = 0;
	data->temp = 0;
	while (x <= data->ar_a[i] && flag == 0)
		i++;
	while (x >= data->ar_a[i] && flag == 1)
		i++;
	best->temp = data->ar_a[i];
	j = 0;
	while (data->ar_a[(data->size_a - 1) - j] >= x && flag == 0)
		j++;
	while (data->ar_a[(data->size_a - 1) - j] <= x && flag == 1)
		j++;
	if (i > j)
	{
		data->temp = 1;
		best->temp = data->ar_a[(data->size_a - 1) - j];	
		return (j);
	}
	return (i);
}

int	ps_seek_number(t_struct *data, t_short *best, int x, int flag)
{
	int	i;
	int j;
	int size;

	i = 0;
	data->temp = 0;
	size = data->size_a - 1;
	while (x != data->ar_a[i] && flag == 0)
		i++;
	while (x != data->ar_a[i] && flag == 1)
		i++;
	j = 0;
	while (data->ar_a[size - j] != x && flag == 0)
		j++;
	while (data->ar_a[size - j] != x && flag == 1)
		j++;
	if (i > j)
	{
		data->temp = 1;
		best->temp = data->ar_a[size - j];	
		return (j);
	}
	return (i);
}

int	ps_id_number(t_short *best)
{
	int	i;

	i = 0;
	while (best->ar[i] != best->nb)
		i++;
	return (i);
}

void	ps_check_min_nb(t_struct *data, t_short *best, int j, int flag)
{
	int	i;
	int	a;
	int b;
	int	range;

	i = 0;
	b = data->size_a;
	range = (data->size_a / 20) + 1;
	while (i < range && j + i < data->size_a)
	{
		a = ps_seek_number(data, best, best->ar[j + i], flag);
		if (a + (i / 2) < b)
		{
			best->nb = best->ar[j + i];
			data->flag = data->temp;
			b = a;
		}
		i++;
	}
}

void	ps_check_max_nb(t_struct *data, t_short *best, int j, int flag)
{
	int	i;
	int	a;
	int b;
	int	range;

	i = 0;
	b = data->size_a;
	range = (data->size_a / 20) + 1;
	while (i < range && j - i > 0)
	{
		a = ps_seek_number(data, best, best->ar[j - i], flag);
		if (a + (i / 2) < b)
		{
			best->nb = best->ar[j - i];
			data->flag = data->temp;
			b = a;
		}
		i++;
	}
}