/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:27:57 by dpadrini          #+#    #+#             */
/*   Updated: 2023/01/20 16:45:04 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_lib/libft.h"
# include "ft_lib/Printf/ft_printf.h"
# include "ft_lib/GetNextLine/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_short
{
	int		*ar;
	int		*moves;
	int		sort_flag;
	int		low_value;
	int		lowmid_value;
	int		highmid_value;
	int		end_value;
	int		mem;
	int		direction;
	int		swapper;
}	t_short;

typedef struct s_struct
{
	int		*ar_a;
	int		*ar_b;
	int		size_a;
	int		size_b;
	int		og_size;
	int		flag;
	int		checker;
}	t_struct;

/* PUSHWAP */
int		main(int argc, char **argv);
void	ps_initialization(t_struct *data, t_short *best, int argc, char **argv);
void	ps_micro_engine(t_struct *data, t_short *best);
void	ps_engine(t_struct *data, t_short *best);

/* INS TRUCTION*/
void	ps_instruction(int *ar, int size, t_struct *data, t_short *best);

/* ENGINE */
void	ps_push_first_sequence(t_struct *data, t_short *best);
void	ps_exe_last_sequence(t_struct *data, t_short *best);
void	ps_order_three(t_struct *data);
void	ps_pull(t_struct *data, t_short *best);
void	ps_circuit(t_struct *data, int i[2]);

/* INIT */
void	ps_init_single(char *ar, t_struct *data, t_short *best);
void	ps_init(char **ar, t_struct *data, t_short *best, int size);
void	ps_parse(t_struct *data, t_short *best, char *subject);
void	ps_limit(t_struct *data, t_short *best, char *number);
void	ps_set_pivot(t_struct *data, t_short *best);

/* MALLOCATION */
int		*ps_mallocation(t_struct *data, t_short *best, int size);
void	ps_deploy_memory(t_struct *data, t_short *best, int size);
void	ps_reset_memory(t_struct *data, t_short *best);
void	ps_free_matrix(char **matrix, int i);

/* PUSHMOVES*/
void	ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b);
void	ps_push_a(t_struct *data);
void	ps_push_b(t_struct *data);

/* REVERSE ROTATIONS*/
void	ps_rev_rotate(int *ar, int size);
void	ps_rev_rotate_a(t_struct *data);
void	ps_rev_rotate_b(t_struct *data);
void	ps_rev_rotate_r(t_struct *data);
void	ps_rrr(t_struct *data);

/* ROTATIONS */
void	ps_rotate(int *ar, int size);
void	ps_rotate_a(t_struct *data);
void	ps_rotate_b(t_struct *data);
void	ps_rotate_r(t_struct *data);
void	ps_rr(t_struct *data);

/* SWAPS */
void	ps_swap(int *a, int *b);
void	ps_swap_a(t_struct *data);
void	ps_swap_b(t_struct *data);
void	ps_swap_s(t_struct *data);
void	ps_ss(t_struct *data);

/* UTILITIES */
void	ps_error(t_struct *data, t_short *best);
void	ps_seek_for_doubles(t_struct *data, t_short *best, int *ar, int size);
void	ps_ar_copy(t_struct *data, t_short *best, int size, int *ar);
void	ps_order(t_short *best, int size, int i, int complete);
void	ps_swap_order(t_short *best, int i, int j);

/* UTILITIES_B */
void	ps_piston(t_struct *data);
int		ft_module(int n);
int		ps_lower_index(int temp[2], int i[2]);
void	ps_get_stack_infos(t_struct *data, int *top, int *size, char stack);
int		ps_get_id(t_struct *data, int i, char stack);

/* FAKE_PULL */
void	ps_fake_pull(t_struct *data, int i[2]);
int		ps_posneg_position(t_struct *data, int val, char stack);
int		ps_get_a_moves(t_struct *data, int val, int flag, char stack);

/* MINMIDMAX */
int		minmidmax(t_struct *data, int bval);

/* ATOI */
int		ps_atoi(const char *str, t_struct *data, t_short *best);

/* BONUS */
int		ps_control(char *moves);
void	ps_check_final(t_struct *data);
int		ps_execute_moves(t_struct *data, char *moves);
void	ps_check_moves(t_struct *data);
int		main(int argc, char **argv);

#endif
