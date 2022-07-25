/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:00:09 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/25 17:40:57 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* # include <sys/wait.h> */

typedef struct s_shortest
{
	int	count
}	t_shorter

typedef struct s_struct
{
	int	*ar_a;
	int	*ar_b;
	int *shortest_ar;
	int	*size_a;
	int	*size_b;
	int	*shortest_size;
}	t_struct

/* PUSH SWAP */

/*  INIT */
int		*ps_init_a(char *arg, int *size);

/* CHECKER */
int		ps_filter(char **matrix, int size);
void	ps_mallok(void *ptr);
int		ps_limit(char *str);

/* UTILITIES */
void	ps_error(void);
