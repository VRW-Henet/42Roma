#include "Push_swap.h"

void	*ps_init_single(char *ar, t_struct data)
{
	char **values;
	int	*ret;
	int i;

	i = 0;
	values = ft_split(ar, ' ');
	while (values[i] != NULL)
	{
		ps_parse(values[i]);
		ret[i] = ft_atoi(values[i]);
		i++;
	}
	data->ar_a = ret;
	data->size_a = i;
}

void	*ps_init(char **ar, t_struct data)
{
	int *ret;
	int i;

	i = 0;
	while (ar[i] != 0)
	{
		ps_parse(ar[i]);
		ret[i] = ft_atoi(ar[i]);
		i++;
	}
	data->ar_a = ret;
	data->size_a = i;
}

void	ps_parse(char *subject)
{
	int i;

	i = 0;
	while (subject)
	{
		if (subject[i] == '-' || subject[i] == '+')
			i++;
		else if (ft_isdigit(subject[i]))
		{
			while (ft_isdigit(subject[i]))
				i++;
			ps_limit(subject);
		}
		else
			ps_error("parse01\nValues don't respect criteria");
	}
}

void	ps_limit (char *number)
{
	long long int	nb;
	int				i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	nb = 0;
	while (number[i] != '\0')
	{
		nb *= 10;
		nb += number[i] - '0';
		i++;
	}
	if (nb > 2147483647)
		ps_error("limit02\nValues over the limits");
}

void	ps_set_pivot (t_struct data, t_short best)
{
	int	size;

	size = data.size_a - 1;
	best->low_value = best.ar[0];
	best->mid_value = best.ar[size / 2];
	best->end_value = best.ar[size];
	if (best.moves[size] > size / 2)
		best->direction = 1;
	else
		best->direction = 0;
}