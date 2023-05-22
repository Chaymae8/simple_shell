#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void shell_prompt() {
    write(STDOUT_FILENO, "$ ", 2);
}

void execute_command(char *command, char *arguments[]) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(command, arguments);

        // execvp only returns if an error occurs
        write(STDERR_FILENO, "Command not found: ", 19);
        write(STDERR_FILENO, command, strlen(command));
        write(STDERR_FILENO, "\n", 1);
        exit(1);
    } else if (pid < 0) {
        write(STDERR_FILENO, "Fork failed\n", 12);
    } else {
        wait(NULL);
    }
}

void built_in_env() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS + 1];

    while (1) {
        shell_prompt();
        ssize_t read_bytes = read(STDIN_FILENO, command, sizeof(command));

        // Remove the newline character at the end of the command
        if (read_bytes > 0 && command[read_bytes - 1] == '\n') {
            command[read_bytes - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            exit(0);
        } else if (strcmp(command, "env") == 0) {
            built_in_env();
        } else if (strlen(command) > 0) {
            char *token = strtok(command, " ");
            int argc = 0;

            while (token != NULL && argc < MAX_ARGUMENTS) {
                arguments[argc++] = token;
                token = strtok(NULL, " ");
            }

            arguments[argc] = NULL;

            execute_command(arguments[0], arguments);
        }
    }

    return 0;
}

