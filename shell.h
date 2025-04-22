#ifndef SHELL_H
#define SHELL_H

/*Librerias estandar*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_TOKENS 64
/* Variable global para entorno*/
extern char **environ;

/* Prototipos */
void shell_loop(void);
char **tokenize_input(char *line);
void execute_command(char **args);
int _strcmp(const char *s1, const char *s2);
void display_prompt(void);
void print_env(void);
int builtin_cd(char **args);
char *find_command_in_path(char *command);

#endif /* SHELL_H */
