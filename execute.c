#include "shell.h"

/**
 * execute_command - Crea un proceso hijo para ejecutar el comando
 * @args: Array de argumentos del comando
 */
void execute_command(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0) /*Proceso hijo*/
	{
		char *command = args[0];
		char *cmd_path = NULL;

		/*Si el comando no tiene "/" (es relativo), buscarlo en el PATH */
		if (strchr(command, '/') == NULL)
			cmd_path = find_command_in_path(command);

		if (cmd_path != NULL)
		{
			execvp(cmd_path, args);
			perror("execvp");
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", command);
		}

		exit(1);
	}
	else /*proceso padre*/
	{
		waitpid(pid, &status, 0);
	}
}
