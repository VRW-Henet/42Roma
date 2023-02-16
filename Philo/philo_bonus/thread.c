/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:56:45 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/14 11:56:46 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	phb_finish(t_philo *ph)
{
	int	tmp;

	tmp = phb_time() - ph->rules->start;
	if (tmp - ph->strv > ph->rules->time_death)
	{
		sem_wait(ph->rules->msg);
		printf("%lld %d died\n", phb_time() - ph->rules->start, ph->id);
		sem_post(ph->rules->dead);
		return (1);
	}
	if (ph->n_eat == ph->rules->must_eat)
	{
		sem_post(ph->rules->finish);
		return (1);
	}
	return (0);
}

void	*phb_monitor(void *philo)
{
	t_philo		*ph;

	ph = philo;
	while (1)
	{
		if (phb_finish(ph) == 1)
			return (NULL);
	}
	return (NULL);
}

void	*phb_meal(void *philo)
{
	t_philo		*ph;

	ph = philo;
	ph->rules->start = phb_time();
	ph->strv = phb_time() - ph->rules->start;
	pthread_create(&ph->death, NULL, phb_monitor, ph);
	if (ph->id % 2 == 0)
		phb_my_sleep(ph->rules->time_eat, ph->rules);
	while (1)
	{
		sem_wait(ph->rules->fork);
		phb_philo_msg(ph->rules, ph->id, "has taken a fork");
		sem_wait(ph->rules->fork);
		phb_philo_msg(ph->rules, ph->id, "has taken a fork");
		phb_philo_msg(ph->rules, ph->id, "is eating");
		ph->n_eat++;
		ph->strv = phb_time() - ph->rules->start;
		phb_my_sleep(ph->rules->time_eat, ph->rules);
		sem_post(ph->rules->fork);
		sem_post(ph->rules->fork);
		phb_philo_msg(ph->rules, ph->id, "is sleeping");
		phb_my_sleep(ph->rules->time_sleep, ph->rules);
		phb_philo_msg(ph->rules, ph->id, "is thinking");
	}
	return (NULL);
}

void	*phb_must_eat(void *rules)
{
	t_rules	*ru;
	int		i;

	ru = rules;
	i = 0;
	while (i < ru->n_ph)
	{
		sem_wait(ru->finish);
		i++;
	}
	i = 0;
	while (i < ru->n_ph)
	{
		kill(ru->philo[i].pid, SIGKILL);
		i++;
	}
	sem_post(ru->dead);
	return (NULL);
}

void	phb_thread(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	pthread_create(&rules->finish_eat, NULL, phb_must_eat, rules);
	i = 0;
	while (i < rules->n_ph)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			phb_meal(&rules->philo[i]);
		i++;
	}
	sem_wait(rules->dead);
	exit (0);
}
