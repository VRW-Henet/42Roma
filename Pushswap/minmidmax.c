
#include "pushswap.h"

int	get_min(t_struct *data)
{
	int *ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (ar[i] < ret)
			ret = ar[i];
		i++;
	}
	return (ret);
}

int	get_max(t_struct *data)
{
	int *ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (ar[i] > ret)
			ret = ar[i];
		i++;
	}
	return (ret);
}

int	get_mid(t_struct *data, int bval)
{
	int *ar;
	int	ret;
	int	i;

	i = 0;
	ar = data->ar_a;
	ret = ar[i];
	while (i < data->size_a)
	{
		if (bval > ar[i] && (i + 1) < data->size_a && bval < ar[i + 1])
		{
			//ft_printf("bval: %d mid chosen: %d\n", bval, ar[i + 1]);
			ret = ar[i + 1];
			break ;
		}
		//else if (!(i + 1 < data->size_a) && bval > ar[i] && bval < ar[0])
		//{
		//	ret = ar[0];
		//	break ;
		//}
		i++;
	}
	return (ret);
}


int	minmidmax(t_struct *data, int bval)
{
	int	min;
	int	mid;
	int	max;

	min = get_min(data);
	//ft_printf("min: %d mid: %d max: %d bval: %d\n\n", min, mid, max, bval);
	if (bval < min)
		return (ps_posneg_position(data, min, 'a'));
	max = get_max(data);
	if (bval > max)
		return (ps_posneg_position(data, min, 'a'));
	mid = get_mid(data, bval);
	return (ps_posneg_position(data, mid, 'a'));
}
