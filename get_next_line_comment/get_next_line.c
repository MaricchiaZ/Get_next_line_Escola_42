/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:57:14 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/07 19:59:21 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//essa função cria e malloca uma nova string que é a união de s1 e s2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest; // criamos um ponteiro para a nova string que será criada
	int		len; // criamos um int len para armazenar o tam das strins s1 e s2
	int		i; // criamos um índice para percorrer a string para a cópia

	len = ft_strlen(s1) + ft_strlen(s2); // len recebe o tamanhoda s1 + o tamanho da s2
	dest = (char *) malloc (sizeof (char) * (len + 1)); //o ponteiro dest recebe a memória reservada para
	// o comprimento das duas strings + 1 byte que é o '\0'
	if (dest == NULL) // se dest for NULL o Malloc deu errado..
		return (NULL); // então retornamos null
	i = 0; // o índice é zerado e ele percorrerá s1
	len = 0; // o len é zerado e será o índice de preenchimento (tamanho) da dest
	while (s1[i] != '\0') // enquanto a s1[i] for diferente do byte nulo
	{
		dest[len++] = s1[i++];  //dest[len] recebe o valor de s1[i], e em seguida
		//fazemos len++ e i++, para avançarmos para as próximas posições
	}
	i = 0; // o índice é zerado novamente, e agora percorrerá s2
	// o len não foi zerado, então a dest continuará ser preenchida, agora com o
	// conteúdo de s2
	while (s2[i] != '\0') // enquanto a s2[i] for diferente do byte nulo
	{
		dest[len] = s2[i]; //dest[len] recebe o valor de s2[i]
		i++; // i ganha uma unidade
		len++; // len ganha uma unidade
	}
	dest[len] = '\0'; //a posição final da dest recebe o byte nulo
	return (dest); // retornamos a dest
}

// essa função lê um BUFFER_SIZE, armazena no store_rest, e confere se esse bloco lido (BUFFER_SIZE), tem uma
// quebra de linha, se não tiver, lê mais um bloco, armazena no fim do store_rest e procura a quebra de linha
// assim, chama repetidamente a função read até que uma quebra de linha seja encontrada, ou acabe o texto para ler
static char	*read_buffers(int fd, char *store_rest, char *buffer) // recebemos o fd do arquivo, o resto do buffer,
// e o buffer
{
	int		read_bytes; // criamos um inteiro que irá receber o número de bytes lidos pela função read
	char	*temp_to_join; // criamos um ponteiro para string que receberá temporariamente o store_rest

	read_bytes = 1; // iniciamos em 1, na verdade serve qualquer valor maior que zero
	while (1) // fazemos um while sempre verdadeiro, pois queremos que ele pare apenas se sair em
	// algum return ou break, isso nos dá certexa de que algum dos objetivos foi atingido
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE); // armazenamos no read_bytes o número de bytes lidos
		// pela função read. A função read lê o arquivo numerado pelo fd, ela lê de x bytes em x bytes, e
		// essa quantidade de bytes é passada pelo BUFFER_SIZE, e por fim, esses x bytes lidos são 
		// armazenados na string buffer
		if (read_bytes == -1) // se read_bytes for -1, deu-se um erro na leitura
			return (NULL); // então retornamos NULL
		else if (read_bytes == 0) // se read_bytes for 0, ou o arquivo a ser lido estpa vazio, ou já
		// acabamos de ler, então...
			break ; // paramos esse while, ou saímos desse loop;
		buffer[read_bytes] = '\0'; // caso tenha ocorrido tudo certo com a leitura, a posição final da string recebe
		// o byte nulo
		if (!store_rest) // se o armazenamento do buffer, o store_rest, estiver vazio
			store_rest = ft_strdup(""); // ele recebe o malloc de uma string vazia, dada pela função ft_strdup
		temp_to_join = store_rest; // temp_to_join recebe bem temporariamente o store_rest
		store_buffer = ft_strjoin(temp_to_join, buffer); // store_rest recebe a junção do store_rest(resto da 
		// leitura anterior) mais o novo buffer lido;
		free(temp_to_join); // damos free na variável temporária
		if (ft_strchr(buffer, '\n')) // se no buffer encontramos uma quebra de linha '\n'...
			break ; // paramos o while, saímos dele
	}
	return (store_rest); // retornamos o store_rest montado com o resto da linha anterior, mais o(s) próximos
	// buffer(s) lido(s), sendo que o último buffer adicionado tem a quebra de linha
}

// essa função separa a linha do resto lido ao encontrar um '\n', o restante que sobrou é colocada no temporariamente
// no rest_buffer e na função get_next_line é armazenada na variável estática.
static char	*separete_line_rest(char *line) // essa função recebe a linha que será aparada;
{
	char	*rest_line; // criamos um ponteiro de string que temporariamente guardará o que for 'descartado'
	// da linha
	int		i; // criamos um índice i para percorrer a linha;

	i = 0; // nosso índice se inicia em zero;
	while (line[i] != '\0' && line[i] != '\n') //equanto a linha[na posição i] não acabar (diferente de '\0'),
	// e também não for a quebra de linha 
		i++; // avançamos para a próxima casa
	if (line[i] == '\0' || line[1] == '\0') // se saiu do while acima e linha[na posição i] é p byte nulo, é por
	// que não encontramos a quebra de linha, e nesse caso não temos rest_buffer para retornar
		return (NULL); // então retornamos NULL
	rest_line = ft_substr(line, i + 1, ft_strlen(line) - i); //o resto da linha, rest_line, recebe a substring
	// da linha iniciando após o caracter \n e até o final da linha (de tamanho ft_strlen(line) - i)
	if (*rest_line== '\0') //se o que foi retirado da linha estiver vazio
	{
		free(rest_line); // damos um free nesse ponteiro rest_line
		rest_line = NULL; //e anulamos o ponteiro também (esta é uma boa prática, mas não é sempre necessário)
	}
	line[i + 1] = '\0'; // a posição i + 1, ou a próxima após a quebra de linha, recebe um \0, finalizando aqui a linha
	return (rest_line); // retornamos a linha
}

//Protótipo: char *get_next_line(int fd);
//Arquivos para entregar: get_next_line.c, get_next_line_utils.c, get_next_line_next_line.h
//Parâmetros fd: O descritor de arquivo a ser lido
//Retorno: Linha de leitura, em cado de comportamento correto ou 
//NULL: quando não há mais nada para ler, ou um erro ocorreu
// Funções permitidas: read, malloc, free
//Descrição: Escreva uma função que retorna uma linha lida a partir de um descritor de arquivo

//esta recebe um fd(file descriptor) de um arquivo aberto no main, e econtra e retorna a primeira 
//linha deste arquivo, ou seja, esta função procura a pimeira quebra de linha "\n".
// A grande dificuldade é que a função precisa funcionar bem independente do BUFFER_SIZE passado.
// A função read lê um bloco de leitura (x bytes) ou (BUFFER_SIZE) de cada vez.
char	*get_next_line(int fd) // a função de leitura recebe o fd passado por parâmetro
{
	char		*line; // criamos um ponteiro para a string que irá receber a linha;
	char		*buffer; // criamos um ponteiro para a string que irá armazenar o "bloco de leitura" da função read.
	static char	*store_rest // criamos um ponteiro para a string que armazenará o resto da linha, depois do
	// '\n', encontrado no último buffer adicionado na linha;
	// essa é uma VARIÁVEL ESTÁTICA, ou seja, ela não é zerada quando a função acaba, ela dura o tempo
	// de execussão do programa 

	if (fd < 0 || BUFFER_SIZE <= 0) // fazemos uma checagem de erro, caso o fd seja inválido (menor que 0)
	// ou o BUFFER_SIZE ou "bloco de leitura" seja menor ou igual a zero
		return (NULL); // devemos retornar NULL
	buffer = (char *) malloc((sizeof(char)) * (BUFFER_SIZE + 1)); // alocamos o espaço para armazenar o bloco lido, e mais o
	// byte nulo
	if (!buffer) //se função malloc não funcionou como deveria, ou seja, não conseguimos reservar por falta de memória
		return (NULL); // retornamos um ponteiro vazio
	line = read_buffers(fd, store_rest, buffer); // a linha recebe o retorno da função que chama repeditadamente
	// a função read e junta os buffers lidos em sequência, até que o último tenha a quebra de linha '\n';
	free(buffer); // limpamos a memória usada para a string buffer
	if (!line) // se a linha estiver vazia, provavelmente já acabou a leitura
		return (line); // retornamos a linha
	store_rest = separete_line_rest(line); //essa função midifica a linha, pois apara a linha no primeiro "\n" encontrado, e o restante, armazena
	// no store_rest;
	return (line); // temos a linha pronta para retornar;
}

/* APAGAR    APAGAR    APAGAR    APAGAR    APAGAR    APAGAR    APAGAR    APAGAR    APAGAR    APAGAR   */

// Para testar sua função use esse main e o arquivo text.txt   ______   (O comando de compilação está abaixo)

// int	main(void)
// {
// 	int	fd;
// 	char *clean;

// 	fd = open("text.txt", O_RDONLY);
// 	clean = get_next_line(fd);
// 	while (clean)
// 	{
// 		printf("%s", clean);
// 		free (clean);
// 		clean = get_next_line(fd);
// 	}
// 	free (clean);
// 	close(fd);
// }

/*

cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h

gcc -Wall -Wextra -Werror -g  get_next_line.c get_next_line_utils.c get_next_line.h

*/