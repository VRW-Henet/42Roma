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
	int		sort_flag;
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
	int		high_values_b;
}   t_struct;

/* init */
void	*ps_init_single(char *ar, t_struct data);
void	*ps_init(char **ar, t_struct data);
void	ps_parse(char *subject);
void	ps_limit (char *number);
void	ps_set_pivot (t_struct data, t_short best);

/* push_swap */
int		main(int argc, char **argv);
void	*ps_instruction(int *ar, int size, t_short best);

/* utilities */
void	ps_error(char *message);
void	ps_seek_for_doubles(int *ar, int size);
int		*ps_ar_copy(int *ar, int size);
void	*ps_order(t_short best, int size);

/* engine */
void	ps_engine(t_struct data, t_short best);

/* swaps */
void	ps_swap(int *a, int *b, int size);
void	ps_swap_ab(int *ar, int size, char *ab);
void	ps_swap_s(int *ar_a, int *ar_b, int size);

/* push_moves */
void	ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b);
void	ps_push_a(t_struct *data);
void	ps_push_b(t_struct *data);

/* rotations */
void	ps_rotate(int *ar, int size);
void	ps_rotate_a(t_struct *data);
void	ps_rotate_b(t_struct *data);
void	ps_rotate_r(t_struct *data);

/* reverse_rotations */
void	ps_rev_rotate(int *ar, int size);
void	ps_rev_rotate_a(t_struct *data);
void	ps_rev_rotate_b(t_struct *data);
void	ps_rev_rotate_r(t_struct *data);

# endif