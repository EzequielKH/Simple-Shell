#include "shell.h"

extern char **environ;
/** 
 * Declaración externa de la variable 'environ
 * que contiene las variables de entorno
 */

/**
 * print_env - Imprime las variables de entorno
 *
 * Descripción: Esta función recorre el arreglo de variables de entor
 * y las imprime en la salida estándar
 */
void print_env(void)
{
	int i = 0;
	/* Indice para recorrer el arreglo de variables de entorno */

	/* Recorre el arreglo 'environ' y lo imprime */
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		/* Imprime la variable de entorno */
		write(STDOUT_FILENO, "\n", 1);
		/* Imprime una nueva línea después de cada variable */
		i++;
		/* Incrementa el índice para la siguiente variable*/
	}
}
