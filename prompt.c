#include "shell.h"

/*
 *
 * displya_prompt - Muestra el promt "$ "
 *
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
