#include "shell.h"

/**
 * make_env - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */

char **make_env(char **env)
{
	char **new = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
	{
		perror("Malloc Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		new[i] = _strdup(env[i]);
	new[i] = NULL;
	return (new);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */

void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
