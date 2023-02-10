/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:16:23 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:41 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ph_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ph_sleep(long long time)
{
	long long	tmp;

	tmp = ph_time();
	usleep(time * 1000 - 20000);
	while (ph_time() < tmp + time)
		continue ;
}

void	ph_philo_msg(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->rules->lock);
	printf("%lld ", ph_time() - ph->rules->start);
	printf("%d %s\n", id, str);
	pthread_mutex_unlock(&ph->rules->lock);
}
