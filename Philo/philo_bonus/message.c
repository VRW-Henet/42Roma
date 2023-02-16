/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:49:58 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/14 11:57:12 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	phb_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	phb_my_sleep(long long time, t_rules *rules)
{
	long long	tmp;

	tmp = phb_time();
	while (time > phb_time() - tmp)
	{
		usleep(50);
	}
	if (rules->start == 1)
		return ;
}

void	phb_philo_msg(t_rules *rules, int id, char *str)
{
	sem_wait(rules->msg);
	printf("%lld ", phb_time() - rules->start);
	printf("%d %s\n", id, str);
	sem_post(rules->msg);
}
