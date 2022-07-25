/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:14:46 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/24 10:06:37 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*gnl_get_line(char *save);
char	*gnl_save(char *save);
char	*gnl_read_and_save(int fd, char *save);

#endif