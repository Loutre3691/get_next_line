/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:45:13 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/23 22:20:46 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char  *s2)
{
	size_t			i;
	size_t			j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = malloc((ft_strlen(s1) + (ft_strlen(s2)) + 1) * 1);
	if (!new)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	while (s2 && s2[j] != '\0')
		new[i++] = s2[j++];
	return (new);
}

