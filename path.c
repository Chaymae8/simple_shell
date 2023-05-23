#include "simple_shell.h"
/**
* find_path - function that search for path
* @envp : globale variable of enveironement
* Return: path
*/
char **find_path(char **envp)
{
	char *g_path, **tokens, *delime;

	delime = ":";
	g_path = _getenv(envp, "PATH");
	tokens = splits(g_path, delime);
	return (tokens);
}
