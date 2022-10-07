/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:44:52 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 20:04:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_MAX
#  define FD_MAX 256
# endif

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
