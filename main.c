#include "main.h"

/**
 * main - Entry point.
 * @ac: argument count.
 * @av: argument.
 * @env: environment.
 * Return: int.
 */
int main(int ac, char **av, char **env)
{
	hsh(ac, av, env);

	return (EXIT_SUCCESS);
}

/**
*handle_sig - handle_sig
*@it: integer representing the received signal (should be SIGINT).
*
*Description: Signal handler for the SIGINT signal (Ctrl+C).
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
