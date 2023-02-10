/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:16:35 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:16:35 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_check_mutex(int flag, t_philo *ph)
{
	int	tmp;

	tmp = 0;
	if (flag == 0)
	{
		pthread_mutex_lock(&ph->rules->die_mutex);
		tmp = ph->rules->die;
		pthread_mutex_unlock(&ph->rules->die_mutex);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(&ph->rules->must_eat_mutex);
		tmp = ph->end;
		pthread_mutex_unlock(&ph->rules->must_eat_mutex);
	}
	return (tmp);
}

void	ph_starving(t_philo *ph)
{
	pthread_mutex_lock(&ph->rules->philo_time);
	ph->strv = ph_time() - ph->rules->start;
	pthread_mutex_unlock(&ph->rules->philo_time);
}

void	ph_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->rules->die_mutex);
	ph->rules->die = 0;
	pthread_mutex_unlock(&ph->rules->die_mutex);
}

int	ph_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	if (ph_check_mutex(0, ph))
		ph_philo_msg(ph, ph->id, "has taken a fork");
	if (ph->rules->n_ph == 1)
		return (1);
	pthread_mutex_lock(ph->left);
	if (ph_check_mutex(0, ph))
		ph_philo_msg(ph, ph->id, "has taken a fork");
	return (0);
}

void	ph_routine(t_philo *ph)
{
	ph_sleep(ph->rules->time_eat);
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
	if (ph_check_mutex(0, ph))
		ph_philo_msg(ph, ph->id, "is sleeping");
	ph_sleep(ph->rules->time_sleep);
	if (ph_check_mutex(0, ph))
		ph_philo_msg(ph, ph->id, "is thinking");
}
