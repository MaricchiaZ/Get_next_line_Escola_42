/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:51:48 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 19:29:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char) c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0' && str[i] == '\0')
		return ((char *)str + i);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*dest;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= len)
		len = len_s - start;
	if (start > len_s)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *) s + start, len + 1);
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len_src;
	char	*cpy;

	i = 0;
	if (!src)
		return ((void *)0);
	len_src = ft_strlen(src);
	cpy = (char *) malloc (sizeof (char) * (len_src + 1));
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}	
	cpy[i] = '\0';
	return (cpy);
}
