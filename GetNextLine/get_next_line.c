/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:55:59 by dpadrini          #+#    #+#             */
/*   Updated: 2022/03/10 11:34:03 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_line(char *line, int fd)
{
	int		count;
	char	*buffer;

	count = 1;
	if (!line)
		line = gnl_calloc(1, 1);
	while (gnl_strchr(line, '\n') == -1 && count > 0)
	{
		buffer = gnl_calloc(1, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0 || (count == 0 && line[0] == 0))
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line = gnl_strjoin(line, buffer);
		free(buffer);
	}
	return (line);
}

char	*gnl_save(char *line, char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
		i++;
	if (line[i] == 0)
	{
		free(line);
		return (NULL);
	}
	tmp = gnl_substr(line, i, gnl_strlen(line) - i);
	free(line);
	line = gnl_substr(tmp, 0, gnl_strlen(tmp));
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*ret;
	size_t		i;

	i = 0;
	if (fd < 0 || fd > 1024)
		return (NULL);
	line[fd] = get_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	while (line[fd][i] != '\n' && line[fd][i])
		i++;
	ret = gnl_substr(line[fd], 0, i + 1);
	line[fd] = gnl_save(line[fd], ret);
	return (ret);
}
