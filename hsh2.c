#include "main.h"


/**
 * command - searches for executable file
 * @env: environment variables
 * @str: string to search for
 *
 * Description: Searches for an executable file named 'str' in the
 * directories listed in the 'PATH' environment variable.
 * Return: str if successful and Null if not
 */

char *command(char **env, char *str)
{
	char *ptr = env_opt(env, "PATH");
	char *toke, *init;
	int x = 0;
	struct stat buf;
	char *ptr_copy;


	if (str == NULL)
		return (NULL);
	ptr_copy = duplicate(ptr);
	if (ptr)
	{
		toke = strtok(ptr_copy, ":");
		while (toke)
		{
			x = strlen(toke);
			init = malloc(sizeof(char) * (x + strlen(str) + 2));
			if (init == NULL)
				return (NULL);
			strcpy(init, toke);
			strcat(init, "/");
			strcat(init, str);
			strcat(init, "\0");
			if (stat(init, &buf) == 0)
			{
				free(ptr_copy);
				return (init);
			}
			else
			{
				free(init);
				toke = strtok(NULL, ":");
			}
		}
		free(ptr_copy);
		if (stat(str, &buf) == 0)
			return (str);
		return (NULL);
	}
	return (NULL);
}
