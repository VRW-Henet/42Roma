/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:19:38 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/20 14:33:41 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_error(void)
{
	ft_putstr_fd("-> Error <-\n", 1);
	exit(1);
}

void	mt_ping(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("input received\n", 1);
		exit (0);
	}
}

void	mt_send_string(char *str, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			if (((str[i] >> bit) & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					mt_error();
			}
			else if (kill(pid, SIGUSR2) == -1)
				mt_error();
			usleep(100);
		}
		i++;
	}
	mt_end(pid);
}

void	mt_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= '0' && av[1][i] <= '9')
				i++;
			else
				mt_error();
		}
		pid = ft_atoi(av[1]);
		signal(SIGUSR2, mt_ping);
		av[2] = ft_strjoin(av[2], "\n");
		mt_send_string(av[2], pid);
		while (1)
			pause();
	}
	ft_printf("-> Error <-\n");
	ft_printf("-> Usage: ./client server_PID string <-\n");
	return (0);
}
