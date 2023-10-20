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
