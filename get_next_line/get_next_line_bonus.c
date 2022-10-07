/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:57:14 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 19:44:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc (sizeof (char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i] != '\0')
		dest[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		dest[len] = s2[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

static char	*read_buffers(int fd, char *store_rest, char *buffer)
{
	int		read_bytes;
	char	*temp_to_join;

	read_bytes = 1;
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!store_rest)
			store_rest = ft_strdup("");
		temp_to_join = store_rest;
		store_rest = ft_strjoin(temp_to_join, buffer);
		free(temp_to_join);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store_rest);
}

static char	*separete_line_rest(char *line)
{
	char	*rest_line;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	rest_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest_line == '\0')
	{
		free(rest_line);
		rest_line = NULL;
	}
	line[i + 1] = '\0';
	return (rest_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*store_rest[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	buffer = (char *) malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_buffers(fd, store_rest[fd], buffer);
	free(buffer);
	if (!line)
		return (line);
	store_rest[fd] = separete_line_rest(line);
	return (line);
}
