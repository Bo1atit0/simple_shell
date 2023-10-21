#include "main.h"
void str_len(void);
/**
*hsh - main entry point of the shell program
*@ac: The number of command-line arguments.
*@argv: An array of command-line argument strings.
*@env: An array of environment variable strings.
*
*Description: It takes input from the user
*, parses it, and executes the
*corresponding command *or program.
*
*Return: 0 on successful execution,
*or EXIT_FAILURE on failure.
*/
int hsh(int ac, char **argv, char **env)
{
structo container[] = {{NULL}, {NULL}, {NULL}, {0}, {0}};
int x, line, parse_ret, executor_ret = 0;
(void)argv;
if (ac == 2)
{
/** set_readfd(structure, argv); **/
}
while (1)
{
signal(SIGINT, handle_sig);
if (interactive_or_not())
{
printf("$ ");
}
line = _getline(container);
if (line == -1)
{
if (interactive_or_not())
{
putchar('\n');
}
return (EXIT_FAILURE);
/* handle error */
}
if (*container->input == '\n' || *container->input == '\0'
	|| *container->input == '#')
{
if (container->input != NULL)
{
free(container->input);
}
continue;
}
parse_ret = parse_line(container);
if (parse_ret == -1)
{
if (!interactive_or_not())
/*printf("\n");*/  /*removed for task 1 to check all */
free(container->input);
continue;
}
if (container->parsed == NULL)
{
printf("\n");
continue;
}
for (x = 0; container->parsed[x]; x++)
{
;
}
container->args = x;
executor_ret = executor(ac, argv, container, env);
release(container);
if (executor_ret == 2)
{
if (!interactive_or_not())
exit(container->exit);
}
}
return (0);
}

