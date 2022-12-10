#include "pushswap.h"

void	ps_fake_pull(t_struct *data, int i[2])
{
	int	temp[2];
	int	j;
	int	val;

	j = 0;
	val = data->ar_b[0];
	while (j < data->size_b)
	{
		temp[0] = minmidmax(data, val);
		if (j >= data->size_b / 2 && data->size_b > 1)
			temp[1] = -(data->size_b - j);
		else
			temp[1] = j;
		if (j == 0 || ps_lower_index(temp, i))
		{
			i[0] = temp[0];
			i[1] = temp[1];
		}
		val = data->ar_b[j + 1];
		j++;
	}
}

int	ps_posneg_position(t_struct *data, int val, char stack)
{
	int	size;
	int	top;
	int	tmp;
	int	i;

	ps_get_stack_infos(data, &top, &size, stack);
	tmp = data->ar_a[top];
	i = 0;
	while (i < size)
	{
		if (tmp == val)
			break;
		tmp = data->ar_a[ps_get_id(data, i++, stack)];
	}
	if (i == size)
		return (0);
	if (i >= (size + 1) / 2)
		i = (size - i) * (-1);
	return (i);
}

static int	ps_calculate_azx(t_struct *data, int val)
{
	int	min;
	int	mid;
	int	max;

	return minmidmax(data, val);

	min = ps_get_a_moves(data, val,  -1, 'a');
	if (val < min)
		return (ps_posneg_position(data, min, 'a'));
	max = ps_get_a_moves(data, val,  1, 'a');
	mid = ps_get_a_moves(data, val,  0, 'a');
	if (max < val && val > mid)
		return (ps_posneg_position(data, min, 'a'));
	return (ps_posneg_position(data, mid, 'a'));
}

static int	part_two(t_struct *data, int *ret, int val, int flag)
{
	int a;

	a = 0;
	if (flag == 0 && val > *ret \
		&& data->ar_a[ps_get_id(data, 0, 'a')] > val)
	{
		*ret = (data->ar_a[ps_get_id(data, 0, 'a')]);
		a = 1;
	}
	else if (flag == 0 && val < *ret \
		&& data->ar_a[(data->ar_a[data->ar_a[0]] + data->size_a - 1) \
		% data->og_size] < val)
		a = 1;
	return (a);
}

int	ps_get_a_moves(t_struct *data, int val, int flag, char stack)
{
	int	size;
	int	tmp;
	int	ret;
	int	i;

	size = data->size_a;
	i = 0;
	ret = data->ar_a[i];
	part_two(data, &ret, val, flag);
	while (i++ < size)
	{
		tmp = data->ar_a[i - 1];
		
		if (flag == 0 && val > tmp \
			&& ps_get_id(data, i, stack) != -1 \
			&& val < data->ar_a[ps_get_id(data, i, stack)])
			ret = data->ar_a[ps_get_id(data, i, stack)];
		if (flag == -1 && ret > tmp)
			ret = tmp;

		if (flag == 1 && ret < tmp && val > tmp)
			ret = tmp;
	}
	return (ret);
}
