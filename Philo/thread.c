/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:17:32 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:57 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_finish(t_philo *ph, int tmp, int i, int check)
{
	i = 0;
	check = 0;
	while (i < ph->rules->n_ph)
	{
		pthread_mutex_lock(&ph->rules->philo_time);
		tmp = ph_time() - ph->rules->start - ph[i].strv;
		pthread_mutex_unlock(&ph->rules->philo_time);
		if (tmp > ph->rules->time_death)
		{
			ph_death(ph);
			usleep(2000);
			ph_philo_msg(&ph[i], ph[i].id, "died");
			return (1);
		}
		if (ph_check_mutex(1, &ph[i]))
			check++;
		i++;
	}
	if (check == ph->rules->n_ph)
	{
		ph_death(ph);
		return (1);
	}
	return (0);
}

void	ph_monitor(void *philo)
{
	t_philo	*ph;
	int		tmp;
	int		i;
	int		check;

	tmp = 0;
	check = 0;
	i = 0;
	ph = philo;
	while (1)
	{
		if (ph_finish(ph, tmp, i, check) == 1)
			break ;
	}
}

void	*ph_meal(void *philo)
{
	t_philo		*ph;

	ph = philo;
	ph_starving(ph);
	if (ph->id % 2 == 0)
		ph_sleep(ph->rules->time_eat);
	while (ph_check_mutex(0, ph))
	{
		if (ph_take_forks(ph) == 1)
			break ;
		if (ph_check_mutex(0, ph))
			ph_philo_msg(ph, ph->id, "is eating");
		ph->n_eat++;
		if (ph->n_eat == ph->rules->must_eat)
		{
			pthread_mutex_lock(&ph->rules->must_eat_mutex);
			ph->end = 1;
			pthread_mutex_unlock(&ph->rules->must_eat_mutex);
		}
		ph_starving(ph);
		ph_routine(ph);
	}
	return (NULL);
}

void	ph_exit(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&rules->philo_time);
		i++;
	}
	pthread_mutex_destroy(&rules->lock);
	pthread_mutex_destroy(&rules->die_mutex);
	pthread_mutex_destroy(&rules->must_eat_mutex);
	free(philo);
	free(rules->forks);
}

void	ph_thread(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	rules->start = ph_time();
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_create(&philo[i].thread, NULL, ph_meal, &philo[i]);
		i++;
	}
	ph_monitor(philo);
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	ph_exit(rules);
}
