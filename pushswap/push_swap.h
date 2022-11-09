#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_lib/libft.h"
# include "ft_lib/Printf/ft_printf.h"
/*# include "ft_lib/GetNextLine/getnextline.h"*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_short
{
	int		*ar;
	int		*moves;
	int		*utility;
	int		nb;
	int		sort_flag;
	int		swapper;
	int		direction;
	int		low_value;
	int		mid_value;
	int		end_value;
}   t_short;

typedef struct s_struct
{
	int		*ar_a;
	int		*ar_b;
	int		size_a;
	int		size_b;
}   t_struct;

/* core */
void	ps_micro_pull(t_struct *data, int size);
void	ps_pull(t_struct *data, int size, t_short *best);
void	ps_minor_combo(t_struct *data);
void	ps_major_combo(t_struct *data);
void	ps_minor_major_combo(t_struct *data);

/* engine */
void	ps_push_first_sequence(t_struct *data, t_short *best);
void	ps_wheel(t_struct *data, t_short *best, int i);
void	ps_push_end_sequence(t_struct *data, t_short *best);
void	ps_exe_last_sequence(t_struct *data, t_short *best);
int		part_two(t_struct *data, t_short *best, int counter, int size);

/* init */
void	ps_init_single(char *ar, t_struct *data, t_short *best);
void	ps_init(char **ar, t_struct *data, t_short *best, int size);
void	ps_parse(char *subject);
void	ps_limit(char *number);
void	ps_set_pivot(t_struct *data, t_short *best);

/* mallocation */
int		*ps_mallocation(int *ar, int size);
void	ps_deploy_memory(t_struct *data, t_short *best, int size);
void	ps_reset_memory(t_struct *data, t_short *best);
void	ps_free_matrix(char **matrix, int i);

/* piston */
void	ps_ar_order(t_struct *data, t_short *best);
void	ps_find_big(t_short *best, int i);
void    ps_get_big(t_struct *data, t_short *best, int i);

/* push_moves */
void	ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b);
void	ps_push_a(t_struct *data);
void	ps_push_b(t_struct *data);

/* push_swap */
int		main(int argc, char **argv);
void	ps_instruction(int *ar, int size, t_struct *data, t_short *best);
void	ps_engine(t_struct *data, t_short *best);

/* reverse_rotations */
void	ps_rev_rotate(int *ar, int size);
void	ps_rev_rotate_a(t_struct *data);
void	ps_rev_rotate_b(t_struct *data);
void	ps_rev_rotate_r(t_struct *data);

/* rotations */
void	ps_rotate(int *ar, int size);
void	ps_rotate_a(t_struct *data);
void	ps_rotate_b(t_struct *data);
void	ps_rotate_r(t_struct *data);

/* swaps */
void	ps_swap(int *a, int *b, int size);
void	ps_swap_a(t_struct *data);
void	ps_swap_b(t_struct *data);
void	ps_swap_s(t_struct *data);

/* utilities */
void	ps_error(char *message);
void	ps_seek_for_doubles(int *ar, int size);
void	ps_ar_copy(t_short *best, int size, int *ar);
void	ps_order(t_short *best, int size);
void	ps_swap_order(t_short *best, int i, int j);

void	ps_show_stacks(t_struct *data);

# endif