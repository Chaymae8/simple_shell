#include "simple_shell"

/**
 *main - main function
 *@ac : arggument count
 *@av : argument vector
 *@envp : globale variable
 *Return: 0
 */
int main(int ac, char **av, char **envp)
{
	(void)ac;
	char *ligne = NULL;
	char *delime = "\t \a\n";
	char *cmd;
	char **tokens;

	tokens = find_path(envp);

	signal(SIGINT, STG_IGN);
	while (1)
	{
		ligne = read_ligne();
		av = splits(ligne, delime);
		cmd = args_path(av, tokens);
		if (cmd == NULL)
			execute(av);
		free(ligne);
		free(av);
		free(cmd);
	}
	return (0);
}
