/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:44:47 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/27 15:04:22 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_help(int fd, char *stash, char *buffer, ssize_t byte)
{


	
}
char *get_next_line(int fd)
{
	char		*buffer;
	ssize_t		byte;
	static char	*stash ;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{ 
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (free (buffer), NULL);
		if (byte == 0)
			break;
		buffer[byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free (buffer), NULL);
	}
	line = ft_line(stash);
	stash = ft_next_line(stash, line);
	if (!line || line[0] == '\0')
		return (free(buffer), free(line), NULL);
	return (free(buffer), line);
}






// int main(void)
// {
// 	int		fd;
// 	int i = 0;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		i++;
// 	}
// 	/*
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	*/
// 	if (fd >= 0)
// 		close(fd);
// 	return (0);
// }