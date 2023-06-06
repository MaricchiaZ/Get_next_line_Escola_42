# Get_next_line_Escola_42

Este é o projeto Get Next Line da Escola42, que tem como objetivo desenvolver uma função em C capaz de ler e retornar uma linha de um arquivo de texto, independente do seu tamanho.

## Sobre o Projeto
O projeto Get Next Line é um exercício desafiador que permite praticar a manipulação de arquivos em C e o gerenciamento de memória. A função get_next_line lê uma linha de um arquivo e a armazena em um ponteiro fornecido como parâmetro. 
É uma tarefa importante para a compreensão de como ler e processar grandes volumes de dados em arquivos de texto, mais importante, de tamanho de buffer variável.
Com esse projeto você deve entender como funciona uma variável estática, ou "static char var".

## Funcionalidades
- Leitura de uma linha de um arquivo de texto
- Suporte para arquivos de qualquer tamanho
- Gerenciamento da memória alocada

## Requisitos
- Conhecimento básico de programação em C
- Compilador de C (GCC)
- Acesso a um ambiente UNIX (Linux ou macOS)

## Instalação e Uso
1. Clone este repositório em seu computador.
```bash
git clone https://github.com/MaricchiaZ/Get_next_line_Escola_42
```
2. Vá até o diretório do projeto.
```bash
cd Get_next_line_Escola_42/get_next_line_comment
```
3. Para testar essa função descomente o main que está no fim do arquivo get_next_line.c
```c
 int	main(void)
{
int	fd;
char *clean;

fd = open("text.txt", O_RDONLY);
clean = get_next_line(fd);
 	while (clean)
 	{
 		printf("%s", clean);
 		free (clean);
 		clean = get_next_line(fd);
 	}
 	free (clean);
 	close(fd);
 }
```
4. Compile o código-fonte.
```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h
```
5. Execute o programa.
```bash
./a.out text.txt
```
Certifique-se de substituir "arquivo.txt" pelo nome do arquivo que você deseja ler.

## Como Usar
Inclua o arquivo get_next_line.h em seu código para ter acesso à função get_next_line.
Chame a função get_next_line passando o descritor de arquivo e um ponteiro para uma string onde a linha será armazenada.
A função retornará 1 se uma linha for lida, 0 se o final do arquivo for alcançado ou -1 em caso de erro.
