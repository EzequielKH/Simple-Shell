#include "shell.h"

/**
 * builtin_cd - Cambia el directorio actual
 * @args: Argumentos, args[0] es "cd", args[1] es el nuevo directorio
 *
 * Return: 0 si tuvo éxito, 1 si hubo un erro
 */
int builtin_cd(char **args)
{
        char *dir = args[1];
	/* Asigna el directorio recibido como argumento */

        /* Si no se pasa un argumento, ir al HOME */
        if (dir == NULL)
                dir = getenv("HOME");
	/* Obtiene la variable de entorno HOME */

        if (dir == NULL)
        {
                perror("cd: HOME not set");
		/* Imprime error si no se encuentra HOME */
                return (1);
        }

        /* Intentar cambiar al directorio */
        if (chdir(dir) != 0)
        {
                perror("cd");
		/* Imprime error si la operación chdir falla */
                return (1);
        }
        return (0);
	/* Retorna 0 si tuvo éxito */
}
