/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:53:09 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/27 17:13:26 by fde-chec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = 0;
	c = (char) c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1 && !*s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	new[i] = '\0';
	return (new);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*new;

	i = 0;
	if (!ft_strchr(stash, '\n'))
		return (stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	new = malloc((i + 2) * 1);
	if (!new)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		new[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_next_line(char *stash, char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	new = malloc(ft_strlen(stash) - ft_strlen(line) + 1);
	if (!new)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
	{
		i++;
		while (stash[i] != '\0')
			new[j++] = stash[i++];
	}
	else
		return (free(new), NULL);
	free(stash);
	new[j] = '\0';
	return (new);
}
