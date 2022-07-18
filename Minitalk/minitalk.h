/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:22:11 by dpadrini          #+#    #+#             */
/*   Updated: 2022/07/18 12:08:55 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* client */
void	mt_error(void);
void	mt_ping(int signal);
void	mt_send_string(char *str, int pid);
void	mt_end(int pid);

/*server */
void	mt_print_str(int sig, siginfo_t *info, void *context);

#endif