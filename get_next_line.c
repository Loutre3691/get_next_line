/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:44:47 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/20 17:44:02 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	ssize_t	byte;
	char	*stash;
	
	byte = 0;
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte += read(fd, buffer, BUFFER_SIZE);
	stash = ft_stash(buffer, )
	while (lire partie)

	return (stash);
}

int main()
{
	int fd;

	fd = open("./paco", O_RDONLY);
	if (fd < 0)
		return (0);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}