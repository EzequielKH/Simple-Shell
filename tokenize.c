#include "shell.h"

/**
 * tokenize_input - Divide la línea de entrada en tokens
 * @line: Línea de entrada
 *
 * Return: Array de punteros a tokens
 */
char **tokenize_input(char *line)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n");
	while (token && i < MAX_TOKENS - 1)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
