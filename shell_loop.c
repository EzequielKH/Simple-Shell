#include "shell.h"

/**
 * shell_loop - Muestra el prompt, lee el input y ejecuta comandos
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		display_prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = tokenize_input(line);		
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				break;
			}
			else if (strcmp(args[0], "env") == 0)
			{
				print_env();
			}
			else if (strcmp(args[0], "cd") == 0)
			{
				builtin_cd(args);
			}
			else
			{
				execute_command(args);
			}
		}
		free(args);
	}
	free(line);
}
