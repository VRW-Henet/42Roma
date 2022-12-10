#include "pushswap.h"

static int	ps_compare(const char *s1, const char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}

static void	ps_check_final(t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (data->ar_a[i] > data->ar_a[i + 1])
		{
			ft_printf("KO");
			return ;
		}
		i++;
	}
	ft_printf("OK");
}

static void	ps_execute_moves(t_struct *data, char *moves)
{
	if (ps_compare("pa\n", moves))
		ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
	else if (ps_compare("pb\n", moves))
		ps_push(data->ar_a, data->ar_b, &data->size_a, &data->size_b);
	else if (ps_compare("rra\n", moves))
		ps_rev_rotate(data->ar_a, data->size_a);
	else if (ps_compare("rrb\n", moves))
		ps_rev_rotate(data->ar_b, data->size_b);
	else if (ps_compare("rrr\n", moves))
		ps_rrr(data);
	else if (ps_compare("sa\n", moves))
		ps_swap(&data->ar_a[0], &data->ar_a[1]);
	else if (ps_compare("sb\n", moves))
		ps_swap(&data->ar_b[0], &data->ar_b[1]);
	else if (ps_compare("ss\n", moves))
		ps_ss(data);
	else if (ps_compare("ra\n", moves))
		ps_rotate(data->ar_a, data->size_a);
	else if (ps_compare("rb\n", moves))
		ps_rotate(data->ar_b, data->size_b);
	else if (ps_compare("rr\n", moves))
		ps_rr(data);
}

static void	ps_check_moves(t_struct *data)
{
	char *moves;

	moves = get_next_line(0);
	while (1)
	{
		if (moves == NULL)
		{
			ft_printf("Error\n");
			return ;
		}
		else
			ps_execute_moves(data, moves);
	}
	ps_check_final(data);
}

int main(int argc, char **argv)
{
	char		*str;
	t_struct	*data;
	t_short		*best;
	int			i;

	str = NULL;
	data = (t_struct *) malloc(sizeof(t_struct));
	best = (t_short *) malloc(sizeof(t_short));
	i = 0;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		ps_init_single(argv[1], data, best);
	else 
		ps_init(argv, data, best, argc - 1);
	ps_seek_for_doubles(data, best, data->ar_a, data->size_a);
		data->flag = 0;
	ps_instruction(data->ar_a, data->size_a, data, best);
	if (best->sort_flag == 1)
		return (0);
	ps_check_moves(data);
	ps_reset_memory(data, best);
	return (0);
}