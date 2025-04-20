#include "shell.h"

/**
 * find_command_in_path - Busca el comando en los directorios de PATH.
 * @command: El comando a buscar.
 *
 * Return: La ruta completa del comando si se encuentra, NULL si no.
 */
char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");  /*Obtiene el PATH del entorno*/
	char *dir;
	char *full_path;
	char *token;

	if (!path)
		return (NULL);
	/*Clonamos PATH para no modificar el original*/
	path = strdup(path);
	if (!path)
		return(NULL);

	token = strtok(path, ":");
	while (token)
	{
		dir = token;
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path);
			return(NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (access(full_path, F_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
