/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:47:53 by xtorres-          #+#    #+#             */
/*   Updated: 2023/03/02 17:47:58 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	freev(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_get_buffer(int fd, char **buffer)
{
	char	aux[BUFFER_SIZE + 1];
	int		sz;

	if (!(*buffer))
		*buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, aux, BUFFER_SIZE);
		if (sz == -1 || (sz == 0 && buffer[0] == '\0'))
		{
			freev(buffer);
			return (NULL);
		}
		aux[sz] = '\0';
		*buffer = ft_join_ptr(*buffer, aux);
		if (ft_strchr(aux, '\n') != 0)
			break ;
	}
	return (*buffer);
}

char	*ft_get_line(char *s, char **rest)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != '\n')
		len++;
	line = (char *) ft_calloc(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i < len + 1)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	*rest = ft_get_rest(&s[i]);
	freev(&s);
	return (line);
}

char	*ft_get_rest(char *s)
{
	char	*rest;
	size_t	i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	rest = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!rest)
		return (NULL);
	while (s[i])
	{
		rest[i] = s[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_buffer(fd, &buffer[fd]);
	if (buffer[fd] == NULL || line[0] == '\0')
	{
		freev(&buffer[fd]);
		return (NULL);
	}
	line = ft_get_line(line, &buffer[fd]);
	return (line);
}
