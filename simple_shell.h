#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
char *read_ligne(void);
char **splits(char *ligne, char *delime);
int execute(char **info);
void _puts(char *s);
int _putchar(char c);
unsigned int _strlen(char *s);
char **find_path(char **envp);
char *_getenv(char **environ, char *dirname);
char *args_path(char **parse, char **new);
char *_strdup(char *string);
char *if_exists(char **environ);
extern char **environ;
#endif
