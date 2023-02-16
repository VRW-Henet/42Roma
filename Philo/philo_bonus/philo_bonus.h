/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:56:25 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/14 11:56:27 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				id;
	int				n_eat;
	long long		strv;
	struct s_rules	*rules;
	pid_t			pid;
	pthread_t		death;
}				t_philo;

typedef struct s_rules
{
	long long		n_ph;
	long long		time_death;
	long long		time_eat;
	long long		time_sleep;
	long long		must_eat;
	long long		start;
	pthread_t		finish_eat;
	sem_t			*msg;
	sem_t			*fork;
	sem_t			*finish;
	sem_t			*dead;
	t_philo			*philo;
}				t_rules;

int			phb_error(void);
void		phb_philo_msg(t_rules *rules, int id, char *str);
int			phb_isspace(char c);
long long	phb_atoi(const char *str);
int			phb_checker(int argc, char *argv[]);
int			phb_limits(long long nb);
long long	phb_time(void);
void		phb_my_sleep(long long time, t_rules *rules);
void		phb_thread(t_rules *rules);
void		phb_exit(t_rules *rules);

#endif