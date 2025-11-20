/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:45:13 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/20 17:42:53 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_read(fd, buffer, BUFFER_SIZE)
{
	ssize_t	byte;
	
	byte = 0;
	if (fd < 0)
		return(-1);
	byte += BUFFER_SIZE
	return (byte);
}

ft_stach()