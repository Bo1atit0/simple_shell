#include "main.h"

/**
 * specifiers - specifiers for builtins
 * @container: pointer
 * @env: environment
 * Return: int
 */
int specifiers(structo *container, char **env)
{
	int x, ret = -1;

	spec specifiers[] = {
		{"env", _my_env},
		{"exit", _my_exit},
		{NULL, NULL}
	};

	for (x = 0; x < 2; x++)
	{
		if (strcmp(container->parsed[0], specifiers[x].symbol) == 0)
		{
			ret = specifiers[x].func(container, env);
		}
	}

	return (ret);
}

/**
 * _my_env - environment
 * @container: pointer
 * @env: environment
 * Return: int
 */
int _my_env(structo *container, char **env)
{
	int y;

	(void)container;

	for (y = 0; env[y]; y++)
	{
		printf("%s\n", env[y]);
	}

	return (0);
}


/**
 * _my_exit - for exits
 * @container: pointer
 * @env: environment
 * Return: int
 */
int _my_exit(structo *container, char **env)
{
	int y = 0, x = 0;

	(void)env;

	if (container->args == 2)
	{
		y = atoi(container->parsed[1]);
		for (x = 0; container->parsed[x]; x++)
		{
			free(container->parsed[x]);
		}
		free(container->parsed);
		free(container->input);

		exit(y);
	}
	else
	{
		for (x = 0; container->parsed[x]; x++)
		{
			free(container->parsed[x]);
		}
		free(container->parsed);
		free(container->input);
		exit(0);
	}

	return (3);
}
