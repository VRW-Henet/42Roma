/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:00:09 by dpadrini          #+#    #+#             */
/*   Updated: 2022/10/10 12:45:06 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* # include <sys/wait.h> */

typedef struct s_shortest
{
	int	count;
	int	moves_a;
	int	moves_b;
	int	na;
	int	nb;
	int	dir_a;
	int	dir_b;
}	t_shortest;

typedef struct s_struct
{
	int	*ar_a;
	int	*ar_b;
	int	*best_ar;
	int	size_a;
	int	size_b;
	int	best_size;
}	t_struct;

/* PUSH SWAP */
int			*ps_trasformer(int *ar, int size);

/*  INIT */
int			*ps_init_a(char *arg, int *size);
int			*ps_init_b(char **matrix, int size);

/* CHECK_UTILS */
int			ps_filter(char **matrix, int size);
void		ps_mallok(void *ptr);
void		ps_limit(char *str);
int			ps_check_doubles(int *ar, int size);
int			ps_order(int *ar, int size);

/* FINDCOMB */
void		ps_findcomb(t_struct *data);
int			**ps_newcomb(t_struct *data);
int			*ps_clone_add(int *ar, int *len, int n);
void		ps_between(int **comb, int num);

/* FINDER */
int			ps_findmin(int *ar, int size);
int			ps_min(int *ar, int size);
int			ps_findlow(int n, int *ar, int size);

/* SWAPS */
void		ps_swap(int *a, int *b, int size);
void		ps_swap_ab(int *ar, int size, char *ab);
void		ps_swap_s(int *ar_a, int *ar_b, int size);

/* UTILITIES */
void		ps_error(char *message);
int			*ps_ardup(int *ar, int size);
void		ps_sort_ar(int *ar, int size);
void		ps_freematrix(int **matrix, int size);

/* ROTATE */

void		ps_shift(int *ar, int size);
void		ps_shift_a(t_struct *data);
void		ps_shift_b(t_struct *data);
void		ps_shift_r(t_struct *data);

/* REV_ROTATE */

void		ps_rev_shift(int *ar, int size);
void		ps_rev_shift_a(t_struct *data);
void		ps_rev_shift_b(t_struct *data);
void		ps_rev_shift_r(t_struct *data);

/* MOVES */
void		ps_engine(t_struct *data);
t_shortest	ps_find_short(t_struct *data);
void		ps_makestruct(t_shortest *small, t_struct *data, int i);
void		ps_direction(int *dir, int *moves, int size, int i);
void		ps_moves(t_struct *data, t_shortest *small);

/* PUSH */
void		ps_push(int *ar_a, int *ar_b, int *size_a, int *size_b);
void		ps_push_a(t_struct *data);
void		ps_push_b(t_struct *data);

#endif
