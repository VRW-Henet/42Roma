/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:18:18 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:34 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_mutex_init(t_rules *rules)
{
	int	i;
	int	ph;

	ph = rules->n_ph;
	pthread_mutex_init(&rules->lock, NULL);
	pthread_mutex_init(&rules->die_mutex, NULL);
	pthread_mutex_init(&rules->must_eat_mutex, NULL);
	pthread_mutex_init(&rules->philo_time, NULL);
	rules->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * ph);
	if (rules->forks == NULL)
		return (1);
	i = 0;
	while (i < ph)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	return (0);
}

int	ph_init_rules(t_rules *rules, char *argv[])
{
	rules->n_ph = ph_atoi(argv[1]);
	rules->time_death = ph_atoi(argv[2]);
	rules->time_eat = ph_atoi(argv[3]);
	rules->time_sleep = ph_atoi(argv[4]);
	rules->die = 1;
	if (ph_limits(rules->n_ph) == 1 || ph_limits(rules->time_death) == 1
		|| ph_limits(rules->time_eat) == 1 || ph_limits(rules->time_sleep) == 1)
		return (1);
	if (ph_mutex_init(rules) == 1)
		return (1);
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->n_ph);
	if (rules->philo == NULL)
		return (1);
	return (0);
}

void	ph_init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_ph)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].n_eat = 0;
		rules->philo[i].end = 0;
		rules->philo[i].rules = rules;
		rules->philo[i].left = &rules->forks[i];
		rules->philo[i].right = &rules->forks[i + 1];
		if (i == rules->n_ph - 1)
			rules->philo[i].right = &rules->forks[0];
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || ph_checker(argc, argv) == 0)
		return (ph_error());
	if (ph_init_rules(&rules, argv) == 1)
		return (ph_error());
	ph_init_philo(&rules);
	if (argc == 6)
	{
		rules.must_eat = ph_atoi(argv[5]);
		if (ph_limits(rules.must_eat) == 1)
			return (ph_error());
	}
	else
		rules.must_eat = -1;
	ph_thread(&rules);
	return (0);
}
