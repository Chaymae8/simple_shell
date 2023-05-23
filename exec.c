#include "simple_shell"
/**
* execute - execute any command
* @info: a character array
* Return: 0
*/
int execute(char **info)
{
	pid_t pidd;
	int st;

	pidd = fork();
	if (pidd == 0)
	{
		if (execve(info[0], info, NULL) == -1)
		{
			perror(info[0]);
			exit(1);
		}
	}
	else if (pidd > 0)
	{
		wait(&st);
	}
	else
		perror("Error:");
	return (0);
}
