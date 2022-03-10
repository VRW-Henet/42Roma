/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:34:14 by dpadrini          #+#    #+#             */
/*   Updated: 2022/03/10 10:26:30 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "stdlib.h"
# include "unistd.h"

size_t	gnl_strlen(const char *s);
int		gnl_strchr(char *s, char c);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	get_line(char *line, int fd);
char	*gnl_save(char *line, char *str);
char	*get_next_line(int fd);

#endif