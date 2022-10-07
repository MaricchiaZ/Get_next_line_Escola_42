/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:51:45 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 19:32:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strdup(const char *s1);

int		ft_strlen(const char *c);

char	*ft_strchr(const char *s, int c);

#endif
