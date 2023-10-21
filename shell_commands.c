#include "main.h"

/**
*for_parsed - prints parsed arguments
*@container: struct containing parsed arguments
*@env: environment variables
*
*Description: prints parsed arguments from container
*Return: void
*/


void for_parsed(structo *container, char **env)
{

if (container->parsed[1][0] == '$')
{
if (strcmp(container->parsed[1], "$$") == 0)
{
substitute(&container->parsed[1], converter_to_strings(getpid(), 10));
}
if (strcmp(container->parsed[1], "$?") == 0)
{
substitute(&container->parsed[1], converter_to_strings(container->exit, 10));
}


if (strcmp(container->parsed[1], "$PATH") == 0)
{
substitute(&container->parsed[1], (env_opt(env, "PATH")));
}
}
}

/**
*executor - executes a command
*@ac: argument count
*@argv: argument vector
*@container: struct containing parsed arguments
*@env: environment variables
*
*Description: function that executes a command
*Return: 0 on success
*/
int executor(int ac, char **argv, structo *container, char **env)
{
int ret = 0;

(void)ac;
(void)argv;

if (strcmp(container->parsed[0], "echo") == 0)
{
for_parsed(container, env);
}

ret = specifiers(container, env);
if (ret == -1)
{
ret = found_command(container, env);
if (ret == -1)
{
printf("./hsh: 1: %s: not found\n", container->parsed[0]);
container->exit = 127;
return (2);
}
else if (ret == 1)
{
return (ret);
}
else
{
free(container->inst);
}
}
return (0);
}

/**
*found_command - finds a command in PATH
*@container: struct containing parsed arguments
*@env: environment variables
*
*Description: function that finds a command in PATH
*
*Return: 0 on success
*/

int found_command(structo *container, char **env)
{
container->inst = command(env, container->parsed[0]);

if (container->inst != NULL)
{
shell_loop(container, env);
if (strcmp(container->inst, container->parsed[0]) == 0)
{
return (1);
}
return (0);
}



return (-1);

}

/**
*shell_loop - loops shell
*@container: struct containing parsed arguments
*@env: environment variables
*
*Description: function that loops the shell
*
*Return: nothing
*/

void shell_loop(structo *container, char **env)
{
pid_t process = fork();
int hold;


if (process == -1)
{

}

if (process == 0)
{
if (execve(container->inst, container->parsed, env) == -1)
{
perror("Error: ");
}
}

else
{
wait(&hold);
if (WIFEXITED(hold) && WEXITSTATUS(hold) != 0)
{
exit(2);
}
}
}
