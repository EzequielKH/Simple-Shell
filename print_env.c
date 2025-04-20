#include "shell.h"

extern char **environ;
/**
 * print_env - Imprime las variables de entorno
 */
void print_env(void)
{
	int i = 0;

	while  (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
