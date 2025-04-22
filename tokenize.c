#include "shell.h"

/**
 * tokenize_input - Divide la línea de entrada en token
 * @line: Línea de entrada a dividir en token
 *
 * Return: Array de punteros a los tokens obtenidos
 *
 * Descripción: Esta función toma una línea de texto y la divide en tok
 * basándose en los delimitadores de espacio, tabulación, retorno de carr
 * y nueva línea. El resultado es un arreglo de punteros que apunta a lo
 * tokens individuales.
 */
char **tokenize_input(char *line)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	/* Reservamos memoria para el arreglo de tokens */
	char *token;
	int i = 0;

	if (!tokens)
		/* Verificamos si la reserva de memoria fue exitosa */
	{
		perror("malloc");
		/* Si falla, imprimimos un error */
		exit(EXIT_FAILURE);
		/* Terminamos el programa con código de error*/
	}

	/** 
	 * Utilizamos strtok para dividir la línea en toke
	 * usando delimitadores como espacio, tabulación, et
	 */

	token = strtok(line, " \t\r\n");
	while (token && i < MAX_TOKENS - 1)
		/* Mientras no se alcance el número máximo de toke*/
	{
		tokens[i] = token;
		/* Asignamos el token al arreglo */
		i++;
		token = strtok(NULL, " \t\r\n");
		/* Conseguimos el siguiente token */
	}
	tokens[i] = NULL;
	/* Terminamos el arreglo de tokens con NULL */
	return (tokens);
	/* Retornamos el arreglo de tokens */
}
