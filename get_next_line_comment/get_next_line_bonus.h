/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:44:52 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 20:08:38 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H //caso a biblioteca não exista
# define GET_NEXT_LINE_H // criamos

# ifndef BUFFER_SIZE // se esquecermos de compilar com a flag do BUFFER_SIZE
#  define BUFFER_SIZE 10 // definimos aqui
# endif // isso não é necessário, mas é uma boa prática

# ifndef FD_MAX // se não tiver um FD_MAX definido
#  define FD_MAX 1023 // definimos como 1024 que é o máximos de File Descriptor do Linux
// deixamos um para o NULL (já que criaremos um array de arrays com esse valor)
# endif // finalizamos essa declaração

# include <unistd.h> // colocamos as bibliotecas que usamos
# include <stdlib.h> 
# include <string.h>

char	*get_next_line(int fd); // aqui colocamos o protótipo das funções

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strdup(const char *s1);

int		ft_strlen(const char *c);

char	*ft_strchr(const char *s, int c);

#endif // finalizamos aqui as declarações que compõe a nossa biblioteca
