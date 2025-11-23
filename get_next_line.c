/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:44:47 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/23 22:42:09 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (byte < 0)
		return (NULL);
	while (!ft_strchr(stash, '\n') && byte > 0)
	{ 
		byte = read(fd, buffer, BUFFER_SIZE);
		buffer[byte] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return(stash);
}

int main()
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		i++;
	}
	close(fd);
	return (0);
}