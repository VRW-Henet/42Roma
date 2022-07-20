/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:19:24 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/20 14:33:11 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_print_str(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 1;

	(void)context;
	if (sig == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	if (i == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		ft_putchar_fd(c, 1);
		i = 1;
		c = 0;
		return ;
	}
	i++;
	c <<= 1;
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sig;

	process_id = getpid();
	ft_printf("Server PID: > ");
	ft_printf("%d", process_id);
	ft_printf(" <\n");
	sig.sa_sigaction = mt_print_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
