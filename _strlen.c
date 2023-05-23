#include "simple_shell.h"
/**
* _strlen - calculate the length of a string
* @s:string
* Return: the number of bytes in the string pointed to by str.
*/
unsigned int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return ((1) + _strlen(s + 1));
}
