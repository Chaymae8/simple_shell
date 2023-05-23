#include "simple_shell.h"
/**
* read_ligne - reads commands
* Return: ligne
*/
char *read_ligne(void)
{
	char *ligne;
	size_t n = 0;
	int ret = 0;

	if (getline(&ligne, &n, stdin) == -1)
	{
		free(ligne);
		exit(-1);
	}
	ret = strlen(ligne);
	ligne[ret - 1] = '\0';
	return (ligne);
}
