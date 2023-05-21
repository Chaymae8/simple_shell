#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;  // External variable for environment variables

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void print_string(const char *str) {
	int i = 0;
	while (str[i] != '\0') {
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}

void print_env() {
	char **env = environ;
	while (*env != NULL) {
		print_string(*env);
		print_string("\n");
		env++;
	}
}

void shell_prompt() {
	char command[MAX_COMMAND_LENGTH];
    
	while (1) {
		print_string("Hishell$ ");  // Display prompt
		if (fgets(command, sizeof(command), stdin) == NULL)
			break;  // Exit if end of file (Ctrl+D) is encountered
        
		command[strcspn(command, "\n")] = '\0';  // Remove newline character
        
		if (strlen(command) == 0)
			continue;  // Ignore empty commands
        
		if (strcmp(command, "exit") == 0)
			break;  // Exit the shell if the command is "exit"
        
		if (strcmp(command, "env") == 0)
				// Print the current environment
				print_env();
				continue;
				}
        
				char *args[MAX_ARGS];
				int arg_count = 0;
        
				// Tokenize the command line into arguments
				char *token = strtok(command, " ");
				while (token != NULL && arg_count < MAX_ARGS - 1) {
				args[arg_count++] = token;
				token = strtok(NULL, " ");
				}
				args[arg_count] = NULL;  // Set the last element to NULL
        
				// Check if the command exists in the PATH
				char *path = getenv("PATH");
				char *path_token = strtok(path, ":");
				int command_exists = 0;
				while (path_token != NULL) {
					char command_path[MAX_COMMAND_LENGTH];
					snprintf(command_path, sizeof(command_path), "%s/%s", path_token, args[0]);
					if (access(command_path, X_OK) == 0) {
						command_exists = 1;
						break;
					}
					path_token = strtok(NULL, ":");
				}
        
				if (!command_exists) {
					print_string("Command not found: ");
					print_string(args[0]);
					print_string("\n");
					continue;
				}
        
				pid_t pid = fork();
       
				if (pid < 0) {
					perror("fork() error");
					exit(EXIT_FAILURE);
				} else if (pid == 0) {
					// Child process
					if (execvp(args[0], args) == -1) {
						perror("execvp() error");
						exit(EXIT_FAILURE);
					}
				} else {
					// Parent process
					int status;
					waitpid(pid, &status, 0);
				}
}

int main() {
	shell_prompt();
	print_string("\nExiting shell.\n");
    
	return 0;
}
