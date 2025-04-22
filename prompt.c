#include "shell.h"

/**
 * display_prompt - Muestra el prompt del shell si está en modo interactiv.
 */
void display_prompt(void)
{
	/* Verifica si la entrada estándar es un terminal (modo interactivo)*/
	if (isatty(STDIN_FILENO))
	{
		/* Escribe el prompt "$ " al usuario */
		write(STDOUT_FILENO, "$ ", 2);
	}
}
