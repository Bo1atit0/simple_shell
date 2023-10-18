#include "main.h"

/**
 * _getline - get input from user
 * @container: struct pointer
 * Return: returns int
 */
int _getline(structo *container)
{
	ssize_t lineptr;
	size_t x;
	int y;
	char *strint = NULL;


	lineptr = getline(&strint, &x, stdin);
	if (lineptr == -1)
	{
		if (strint != NULL)
		{
			free(strint);
		}
		return (-1);
	}

	for (y = 0; strint[y]; y++)
	{
		if (strint[y] == '#')
		{
			strint[y] = '\0';
		}
	}

	container->input = strdup(strint);

	free(strint);
	return (1);
}

/**
 * interactive_or_not - from stdin or not
 * Return: int
 */
int interactive_or_not(void)
{
	return (isatty(STDIN_FILENO));
}


/**
 * handle_sig - handle signals
 * @it: int
 */
void handle_sig(int it)
{
	int x = 0;

	if (it == SIGINT)
	{
		x = write(STDOUT_FILENO, "\n$ ", 3);
		if (x == -1)
		{
			;
		}
	}
}
