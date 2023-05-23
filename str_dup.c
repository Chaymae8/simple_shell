#include "simple_shell"

/**
 *_strdup -function creat a duplicate of string pointed by string
 *@string: the string
 *
 *Return: a null pointer
 */

char *_strdup(const char *string)
{
	char *D;
	int x;

	if (string == NULL)
		return (NULL);
D = malloc(strlen(string) + 1);

	if (D == NULL)
		return (NULL);

	x = 0;

	while (string[x] != '\0')
	{
		D[x] = string[x];
		x++;
	}

	D[x] = '\0';
	return (D);
}
