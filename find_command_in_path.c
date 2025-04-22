#include "shell.h"

/**
 * find_command_in_path - Busca el comando en los directorios de PATH.
 * @command: El comando a buscar.
 *
 * Return: La ruta completa del comando si se encuentra, NULL si no.
 *
 * Descripción: Esta función busca un comando dentro de los directorios
 * especificados en la variable de entorno PATH. Si el comando se encuentra
 * en uno de esos directorios, se retorna la ruta completa del comando.
 * Si no se encuentra, la función retorna NULL.
 */
char *find_command_in_path(char *command)
{
	/* Obtener la variable PATH desde el entorno */
	char *path_env = getenv("PATH");
	char *path_copy, *dir, *full_path;

	if (!path_env)
		/* Si no se encuentra PATH en el entorno, retornamos NULL */
		return (NULL);

	/* Copiamos el contenido de PATH para no modificar la original */
	path_copy = strdup(path_env);
	if (!path_copy)
		/* Verificamos si la duplicación fue exitosa */
		return (NULL);

	/* Dividimos el PATH usando ':' como delimitador para obtener cada directorio */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		/* Reservamos memoria para la ruta completa */
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
			/* Verificamos si la reserva de memoria fue exitosa */
		{
			free(path_copy);
			return (NULL);
		}

		/* Construimos la ruta completa concatenando el directorio y el comando */
		sprintf(full_path, "%s/%s", dir, command);

		/* Verificamos si el archivo existe y tiene permisos de ejecución */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
			/* Ruta encontrada, retornamos la ruta completa */
		}
		free(full_path);
		/* Liberamos memoria si no se encontró el comando */
		dir = strtok(NULL, ":");
		/* Continuamos con el siguiente directorio */
	}

	free(path_copy);
	/* Liberamos la memoria duplicada de PATH */
	return (NULL);
	/* Si no se encontró el comando, retornamos NULL */
}
