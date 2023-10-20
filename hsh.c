#include "main.h"

/**
*hsh - main entry point of the shell program
*@ac: The number of command-line arguments.
*@argv: An array of command-line argument strings.
*@env: An array of environment variable strings.
*
*Description: It takes input from the user, parses it,
*and executes the corresponding command *or program.
*
*Return: 0 on successful execution, or EXIT_FAILURE on failure.
*/

int hsh(int ac, char **argv, char **env)
{
	structo container[] = {{NULL}, {NULL}, {NULL}, {0}, {0}};
	int x, line, parse_ret; /** executor_ret = 0; **/

	(void)argv;
	while (1)
	{
		signal(SIGINT, handle_sig);
		if (interactive_or_not())
			printf("$ ");
		line = _getline(container);
		if (line == -1)
		{
			if (interactive_or_not())
				putchar('\n');
			return (EXIT_FAILURE);
			/* handle error */
		}
		if (*container->input == '\n' || *container->input == '\0'
				|| *container->input == '#')
		{
			if (container->input != NULL)
				free(container->input);
			continue;
		}
		parse_ret = parse_line(container);
		if (parse_ret == -1)
		{
			if (!interactive_or_not())
				printf("\n");
			free(container->input);
			continue;
		}
		for (x = 0; container->parsed[x]; x++)
			;
		container->args = x;
		executor(ac, argv, container, env);
		for (x = 0; container->parsed[x]; x++)
			free(container->parsed[x]);
		free(container->parsed), free(container->input);
	}
	return (0);
}

/**
*env_opt - prints the environment variables
*@env: environment variables
*@str: string to print
*
*Description: a function that prints the environment variables
*
*Return: env
*/

char *env_opt(char **env, char *str)
{
	int x;

	for (x = 0; env[x]; x++)
	{
		if (commence(env[x], str) == 0)
		{
			return (env[x]);
		}
	}
	return (NULL);
}

/**
*commence - compares two strings
*@str: pointer to first string
*@ptr: pointer to second string
*
*Description: compares the characters in two *strings,
*`str` and *`ptr`, starting from the beginning and continuing until a
*difference is found or the *end of either string is reached.
*
*Return: 0 or 1
*/

int commence(char *str, char *ptr)
{
	int i = 0;

	while (ptr[i])
	{
		if (str[i] != ptr[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

