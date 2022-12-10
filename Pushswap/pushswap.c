#include "pushswap.h"

int main(int argc, char **argv)
{
	t_struct	*data;
	t_short		*best;

	if (argc <= 1)
		return (-1);
	data = (t_struct *) malloc(sizeof(t_struct));
	best = (t_short *) malloc(sizeof(t_short));
	if (!data || !best)
		return (1);
	ps_initialization(data, best, argc, argv);
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
	data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
		return (0);
	if (data->size_a <= 7)
		ps_micro_engine(data, best);
	else 
		ps_engine(data, best);
	ps_reset_memory(data, best);
	return (0);
}

void	ps_initialization(t_struct *data, t_short *best, int argc, char **argv)
{
	if (argc == 2)
		ps_init_single(argv[1], data, best);
	else 
		ps_init(argv, data, best, argc - 1);
	data->og_size = data->size_a;
}

void	ps_micro_engine(t_struct *data, t_short *best)
{
	if (data->size_a == 2)
	{
		if (data->ar_a[0] > data->ar_a[1])
			ps_swap_a(data);
	}
	else if  (data->size_a == 3)
		ps_order_three(data);
	else if (data->size_a <= 7)
	{
		while (data->size_a != 3)
			ps_push_b(data);
		ps_order_three(data);
		ps_pull(data, best);
	}
}

void	ps_engine(t_struct *data, t_short *best)
{
	ps_push_first_sequence(data, best);
	ps_exe_last_sequence(data, best);
	ps_order_three(data);
	ps_pull(data, best);
}

void	ps_show_stacks(t_struct *data, t_short *best)
{
	int	i;

	i = 0;

	ft_printf("low = %d\nlowmid = %d\nhighmid = %d\nend = %d\n", best->low_value, best->lowmid_value, best->highmid_value, best->end_value);
	ft_printf("ar_A			ar_B			Best\nsize:%d			size:%d			size:%d\n", data->size_a, data->size_b, data->og_size);
	while (i < (data->size_a  + data->size_b))
	{
		ft_printf("%d			%d			%d %d\n", data->ar_a[i], data->ar_b[i], best->ar[i], i);
		i++;
	}
}
