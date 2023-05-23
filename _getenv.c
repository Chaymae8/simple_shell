#include "simple_shell.h"
/**
* length - function that checks if the charactere
* @string: the string that pointed
* Return: string
*/
char *length(char *string)
{
	int x;

	for (x = 0; string[x] != '='; x++)
		;
	return (string + x + 1);
}
/**
* compare - compare strings
* @varname: string
* @dirname: string
* Return: 1
*/
int compare(char *varname, char *dirname)
{
	int x;

	for (x = 0; dirname[x] != '\0'; x++)
	{
		if (dirname[x] != varname[x])
			return (1);
	}
}
/**
* _getenv - function searche and get the path in environ
* @environ : variable
* @dirname : charactere
* Return: a pointer to the corresponding value string.
*/
char *_getenv(char **environ, char *dirname)
{
	int h, y;
	char *var_name, *last;

	for (y = 0; environ[y]; y++)
	{
		var_name = malloc(1024);

		for (h = 0; environ[y][h] != '='; h++)
			var_name[h] = environ[h][y];
		if (compare(var_name, dirname))
		{
			last = length(environ[y]);
			free(var_name);
			return (last);
		}
		free(var_name);
	}
	return (NULL);
}
