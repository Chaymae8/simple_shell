#include "simple_shell.h"
/**
* _puts - writes the string
* @s: string
*/
void _puts(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		_putchar(s[x]);
	}
}
