/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:46:28 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 19:44:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retorna um ponteiro para a primeira ocorrência de c na string s
char	*ft_strchr(const char *s, int c)
{
	int				i; // criamos um índice que irá ser usado para percorrer a string
	unsigned char	*str; //criamos um ponteiro auxiliar para receber a string s

	str = (unsigned char *)s; //str recebe o ponteiro da string s convertido para unsigned char
	i = 0; // o ínice começa em zero
	while (str[i] != '\0') // enquanto o str[i] for diferente de nulo, ou seja, não for nulo...
	{
		if (str[i] == (unsigned char) c) // se o conteúdo de str[i] fo idêntico ao C já concertido para unsigned char
		// quer dizer que encontramos a primeira ocorrência de c na string
			return ((char *)str + i); // então retornamos retornamos nosso ponteiro de str já convertido pra ponteiro char
			//adicionado até a posição encontrada
		i++; // caso contrário, apenas vamos para a próxima posição
	}
	if (c == '\0' && str[i] == '\0') // se o caracter que queremos encontrar é o byte nulo, e a str[i] é o byte nulo 
		return ((char *)str + i); // então retornamos retornamos nosso ponteiro de str já convertido pra ponteiro char
			//adicionado até a posição encontrada
	return (NULL); // caso contrário, não econtramos o caracter pedido na strig então retornamos nulo
}

//essa função mede o tamanho da string passada
int	ft_strlen(const char *s)
{
	int	i; // criamos um índice

	i = 0; // i índice inicia em zero
	while (s[i] != '\0') // enquanto o conteúdo da string s na posição i for diferente de nulo
	{
		i++; // nosso índice ganha uma unidade
	}
	return (i); //retornamos o valor do índice que corresponte a quantos bytes da string estão preenchidos
}

// essa função cria uma substring de s, de s[start] até s[start + len]
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s; // criamos uma variável que irá receber o tamanho da string s
	char	*dest; // criamos um ponteiro para a string que vammos criar 

	if (!s) // se a string s falsa, isto é for nula 
		return (NULL); // retornamos NULL
	len_s = ft_strlen(s); // len_s recebe o tamanho da string s medido pela função ft_strlen
	if (len_s <= len) // se a string s for menor que o len passado por parâmetro
		len = len_s - start; // len recebe o tamanho da string s - menos os bytes que deverão
	// estar avançados representados pelo start; com isso temos o comprimento da substring a ser criada
	if (start > len_s) //se a posição de start estiver para além do comprimento...
		return (ft_strdup("")); // retornamos um ponteiro nulo, criado pela função strdup quando recebe
		// uma string vazia ""
	dest = (char *)malloc(sizeof(char) * (len + 1)); // dest recebe a reserva da memória de len bytes mais um (do nulo)
	if (!dest) // se depois do malloc dest for igual a NUll, o malloc deu errado
		return (NULL); // então retornamaos null
	ft_strlcpy(dest, (char *) s + start, len + 1); // casp esteja tudo certo a função ft_strlcpy copia a string s
	// para a dest, comecando pelo ponteiro s na posição start (já convertido para um ponteiro char), e prossegue
	// a cópia até len + 1 bytes
	return (dest); // dest está pronta para ser retornada :) FIM
}

//essa função copia a string src na dest até o size passado
//essa função faz a cópia e retorna o valor de src
size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	i; // criamos um índice i;
	size_t	len_src; // criamos uma variável para armazenar o tamanho de src

	i = 0; // o índice inicia em zero
	len_src = 0; // inicia em zero
	while (src[len_src] != '\0') // enquanto o conteúdo desrc[len_src] for diferente de nulo
		len_src++; // avançamos no len_src, por fim essa variável terá o valor do tamanho de src
	if (size != 0) // se o size passado não for zero
	{
		while (src[i] != '\0' && i < (size - 1)) //enquanto src[i] não for nulo e
		// o índice da cópia forem menor do que o size total passado -1 byte (que está reservado pro byte nulo)
		{
			dest[i] = src[i]; // dest na posição i recebe o valor de src na posição i
			i++; // e seguimos para o próximo byte
		}
		dest[i] = '\0'; // o byte final da dest, que corresponde ao size passado recebe o '\0'
	}
	return (len_src); // retornamos o tamanho de src
}

//essa função duplica alocando uma string
char	*ft_strdup(const char *src)
{
	int		i; // criamos um índíce para percorrer a string
	int		len_src; //criamos uma variável que armazenará o tamanho da sring recebida
	char	*cpy; // criamos um ponteiro que receberá a cópia da string passada

	i = 0; // o índice inicia zerado
	if (!src) // se a src for falsa, isto é não existir
		return ((void *)0); // retornamos um ponteiro vazio
	len_src = ft_strlen(src); //len_src recebe o tamanho da src, obtido pela função ft_strlen() 
	cpy = (char *) malloc (sizeof (char) * (len_src + 1)); // a nova string cpy recebe o malloc (a reserva)
	// dos bytes referentes a char do tamanho da src + 1 byte (o byte nulo)
	if (cpy == NULL) // se cpy for NULL o Malloc deu errado..
		return (NULL); // então retornamos null
	while (src[i]) // enquanto a src existir, isto é não for nula
	{
		cpy[i] = src[i]; // a string nova na posição i recebe o valor da src na posição i
		i++; // vamos para a próxima posição
	}	
	cpy[i] = '\0'; // a posição final da nossa string nova recebe o byte nulo
	return (cpy); // retornamos nossa nova string
}
