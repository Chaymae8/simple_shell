#include "main.h"
/**
* _realloc - reallocation of memory
* @ptr: pointer
* @pld_size: old size of pointer
* @new_size: new size of pointer
* Return: new size of pointer
*/
void *_realloc(void *ptr, unsigned int pld_size, unsigned int new_size)
{
	char *new;
	char *old;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		for (x = 0; x < old_size; x++)
			new[x] = old[x];
		free(ptr);
		for (x = old_size; x < new_size; x++)
			new[x] = '\0';
	}
	if (new_size < old_size)
	{
		for (x = 0; x < new_size; x++)
			new[x] = old[x];
		free(ptr);
	}
	return (new);
}
/**
* splits - function that create tokens
* @ligne: string
* @delime: string
* Return: double pointer
*/
char **splits(char *ligne, char *delime)
{
	char **ptoken;
	int buffer = 1024, i = 0;

	ptoken = malloc(sizeof(char *) * buffer);
	if (!ptoken)
		exit(99);
	ptoken[i] = strtok(ligne, delime);
	x++;
	while (1)
	{
		ptoken[x] = strtok(NULL, delime);
		if (x >= buffer)
		{
			buffer += buffer;
			ptoken = _realloc(ptoken, buffer, buffer * (sizeof(char *)));
			if (!ptoken)
				exit(98);
		}
		if (ptoken[x] == NULL)
			break;
		x++;
	}
	return (ptoken);
}
