#include "push_swap.h"

int main(int argc, char **argv)
{
	t_struct	*data;
	t_short		*best;

	data = (t_struct *) malloc(sizeof(t_struct));
	best = (t_short *) malloc(sizeof(t_short));
	if (!data || !best)
		return (1);
	ps_initialization(data, best, argc, argv);
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
	data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
		ps_error(data, best, "instruction01\nThe values are already in sequence.");
	if (data->size_a <= 7)
		ps_micro_engine(data, best);
	else 
		ps_engine(data, best);
	ps_reset_memory(data, best);
	return (0);
}

void	ps_initialization(t_struct *data, t_short *best, int argc, char **argv)
{
	if (argc <= 1)
		ps_error(data, best, "main01\nInvalid Input, add more arguments");
	else if (argc == 2)
		ps_init_single(argv[1], data, best);
	else 
		ps_init(argv, data, best, argc - 1);
	data->og_size = data->size_a;
}

void	ps_instruction(int *ar, int size, t_struct *data, t_short *best)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ps_ar_copy(data, best, size, ar);
	ps_order(best, size);
	while (i < size)
	{
		j = 0;
		while (best->ar[i] != ar[j] && j < size)
			j++;
		best->moves[i] = j;
		i++;
	}
	ps_set_pivot(data, best);
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
	if (best->sort_flag != 1 && data->size_a > 3)
		ps_push_end_sequence(data, best, data->size_a - 1);
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag != 1 && data->size_a > 3)
		ps_exe_last_sequence(data, best);
	else 
		ps_order_three(data);
	if (data->size_a < 2)
		ps_micro_pull(data, data->size_b - 1);
	ps_pull(data, best);
}

void	ps_show_stacks(t_struct *data)
{
	int	i;

	i = 0;
	
	ft_printf("ar_A			ar_B\nsize:%d			size:%d\n", data->size_a, data->size_b);
	while (i < (data->size_a  + data->size_b))
	{
		ft_printf("%d			%d\n", data->ar_a[i], data->ar_b[i]);
		i++;
	}
}
