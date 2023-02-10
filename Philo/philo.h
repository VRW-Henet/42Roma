/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:17:18 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:17:21 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				n_eat;
	long long		strv;
	int				end;
	struct s_rules	*rules;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	pthread_t		monitor;
}				t_philo;

typedef struct s_rules
{
	long long		n_ph;
	long long		time_death;
	long long		time_eat;
	long long		time_sleep;
	long long		must_eat;
	long long		start;
	int				die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	must_eat_mutex;
	pthread_mutex_t	philo_time;
	t_philo			*philo;
}				t_rules;

int			ph_error(void);
void		ph_starving(t_philo *ph);
void		ph_death(t_philo *ph);
int			ph_take_forks(t_philo *ph);
void		ph_routine(t_philo *ph);
void		ph_philo_msg(t_philo *ph, int id, char *str);
long long	ph_atoi(const char *str);
int			ph_checker(int argc, char *argv[]);
int			ph_limits(long long nb);
long long	ph_time(void);
void		ph_sleep(long long time);
void		ph_thread(t_rules *rules);
int			ph_check_mutex(int flag, t_philo *ph);

#endif