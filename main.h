#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
extern char **environ;

void shell_prompt(void);
void execute_command(char *command, char *arguments[]);
void built_in_exit(void);
void built_in_env(void);
int parse_arguments(char *line, char *arguments[]);
#endif
