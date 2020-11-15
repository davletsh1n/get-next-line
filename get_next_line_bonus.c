/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:09:58 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/15 13:10:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		offset(int i, int fd, char **readed)
{
	char *temp;

	temp = ft_strdup(readed[fd] + i + 1);
	if (temp == NULL)
		return (-1);
	free(readed[fd]);
	readed[fd] = temp;
	return (1);
}

static int		fail(int fd, char **readed)
{
	if (readed[fd])
	{
		free(readed[fd]);
		readed[fd] = NULL;
	}
	return (-1);
}

static int		cutter(int fd, char **line, char **readed)
{
	int i;

	i = 0;
	while (readed[fd][i] != '\n' && readed[fd][i] != '\0')
		i++;
	if (readed[fd][i] == '\n')
	{
		*line = ft_substr(readed[fd], 0, i);
		if (*line == NULL)
			return (fail(fd, readed));
	}
	else if (readed[fd][i] == '\0')
	{
		*line = ft_strdup(readed[fd]);
		if (*line == NULL)
			return (fail(fd, readed));
		free(readed[fd]);
		readed[fd] = NULL;
		return (0);
	}
	return (offset(i, fd, readed));
}

int				get_next_line(int fd, char **line)
{
	static char		*readed[256];
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	int				n;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	readed[fd] = (!readed[fd] ? ft_strdup("") : readed[fd]);
	while (!(ft_strchr(readed[fd], '\n')) &&
		(n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		temp = ft_strjoin(readed[fd], buf);
		if (!temp)
			return (fail(fd, readed));
		free(readed[fd]);
		readed[fd] = temp;
	}
	return (cutter(fd, line, readed));
}
