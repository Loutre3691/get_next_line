/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:45:36 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/20 16:54:35 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);


#endif