/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:48:16 by dpadrini          #+#    #+#             */
/*   Updated: 2023/02/14 11:55:54 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static sem_t	*phb_semaphore(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value));
}

int	phb_init_rules(t_rules *rules, char *argv[])
{
	rules->n_ph = phb_atoi(argv[1]);
	rules->time_death = phb_atoi(argv[2]);
	rules->time_eat = phb_atoi(argv[3]);
	rules->time_sleep = phb_atoi(argv[4]);
	if (phb_limits(rules->n_ph) == 0 || phb_limits(rules->time_death) == 0
		|| phb_limits(rules->time_eat) == 0
		|| phb_limits(rules->time_sleep) == 0)
		return (0);
	rules->msg = phb_semaphore("/message", 1);
	rules->fork = phb_semaphore("/forks", rules->n_ph);
	rules->finish = phb_semaphore("/must_eat", 0);
	rules->dead = phb_semaphore("/dead", 0);
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->n_ph);
	if (rules->philo == NULL)
		return (0);
	return (1);
}

void	phb_init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_ph)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].n_eat = 0;
		rules->philo[i].rules = rules;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || phb_checker(argc, argv) == 0)
		return (phb_error());
	if (phb_init_rules(&rules, argv) == 0)
		return (phb_error());
	phb_init_philo(&rules);
	if (argc == 6)
	{
		rules.must_eat = phb_atoi(argv[5]);
		if (phb_limits(rules.must_eat) == 0)
			return (phb_error());
	}
	else
		rules.must_eat = -1;
	phb_thread(&rules);
	return (0);
}
