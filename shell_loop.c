#include "shell.h"

/**
 * shell_loop - Muestra el prompt, lee el input del usuario y ejecuta comandos.
 */
void shell_loop(void)
{
	char *line = NULL;
	/* Línea de entrada del usuario*/
	size_t len = 0;
	/* Tamaño del buffer de entrada*/
	ssize_t nread;
	/* Número de caracteres leído*/
	char **args;
	/* Array de argumentos obtenidos de la entrada */

	while (1)
	/* Bucle principal del shell */
	{
		display_prompt();
		/* Muestra el prompt al usuario */

		nread = getline(&line, &len, stdin);
		/* Lee la entrada del usuario */
		if (nread == -1)
		/* Si ocurre error o EOF (Ctrl+D) */
		{
			free(line); 
			/* Liberamos la línea leí*/
			if (isatty(STDIN_FILENO))
			/* Si estamos en modo interactivo */
				write(STDOUT_FILENO, "\n", 1);
				/* Imprime salto de líne*/
			break; 
			/* Sale del bucle */
		}

		args = tokenize_input(line);
		/* Divide la línea en argumento*/

		if (args[0] != NULL)
		/* Si hay al menos un comando */
		{
			if (strcmp(args[0], "exit") == 0)
			/* Si el comando es "exit" */
			{
				free(args);
				/* Libera los argumentos */
				break;
				/* Sale del shell */
			}
			else if (strcmp(args[0], "env") == 0)
			/* Si el comando es "env" */
			{
				print_env();
				/* Imprime las variables de entorno */
			}
			else if (strcmp(args[0], "cd") == 0)
			/* Si el comando es "cd" */
			{
				builtin_cd(args);
				/* Cambia de directorio */
			}
			else
			/* Si es un comando externo */
			{
				execute_command(args);
				/* Ejecuta el comando */
			}
		}

		free(args);
		/* Libera los argumentos al final del ciclo */
	}

	free(line);
	/* Libera la línea al salir del bucl*/
}
