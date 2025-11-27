/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:52:47 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/27 17:12:13 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_help(int fd, char *stash)
{
	char		*buffer;
	ssize_t		byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (stash);
	byte = 1;
	while (byte > 0 && !ft_strchr(stash, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (free(buffer), NULL);
		if (byte == 0)
			break ;
		buffer[byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = gnl_help(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	stash[fd] = ft_next_line(stash[fd], line);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
