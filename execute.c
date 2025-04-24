#include "shell.h"


extern char **environ;

/**
 * execute_command - Crea un proceso hijo para ejecutar el comando
 * @args: Array de argumentos del comando
 *
 * Descripción: Esta función maneja la ejecución de un comando dentro de
 * proceso hijo. Primero verifica si el comando tiene una ruta absoluta o
 * relativa, en cuyo caso se intenta ejecutar directamente. Si el comando
 * no tiene ruta, busca el comando en los directorios especificados en el
 * entorno PATH. Luego, crea un proceso hijo para ejecutar el comando usando
 * `execve`. Si ocurre un error, imprime un mensaje apropiado.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *command = args[0];
	char *full_path = NULL;

	/* Si es ruta absoluta o relativa, intentar ejecutar directamente */
	if (command[0] == '/' || command[0] == '.')
	{
		/* Verificar si el comando es accesible y ejecutable */
		if (access(command, X_OK) != 0)
		{
			perror("Command not found");
			return;
		}
	}
	else
	{
		/* Buscar el comando en los directorios de PATH */
		full_path = find_command_in_path(command);
		if (!full_path)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			return;
		}
		args[0] = full_path;  /* Reemplazar el comando por la ruta completa */
	}

	pid = fork();  /* Crear un proceso hijo */
	if (pid == 0)
	{
		/* En el proceso hijo, intentar ejecutar el comando */
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/* En el proceso padre, esperar a que el hijo termine */
		waitpid(pid, &status, 0);
	}
	else
	{
		/* Error al crear el proceso hijo */
		perror("fork");
	}

	/* Liberar la memoria utilizada por la ruta completa si se encontró*/
	if (full_path)
		free(full_path);
}
