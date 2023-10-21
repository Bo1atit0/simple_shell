#include "main.h"
/**
 *release - Release memory associated with the container.
 *@container: a pointer to the container structure
 *
 *Desc: This function frees the memory allocated for parsed data and input data
 */
void release(structo *container)
{
int x;

for (x = 0; container->parsed[x]; x++)
{
free(container->parsed[x]);
}
free(container->parsed);
free(container->input);
}

/**
*env_opt - prints the environment variables
*@env: environment variables
*@str: string to print
*
*Description: a function that
*prints the environment variables
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
*Description: compares the characters
*in two *strings, `str` and *`ptr`, starting
*from the beginning and *continuing until a *difference is
*found or the *end of either string is reached.
*If a *difference is found.
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


/**
*command - searches for executable file
*@env: environment variables
*@str: string to search for
*
*Description: Searches for an
*executable file named 'str' in the
*directories listed in the 'PATH'
*environment variable.
*
*Return: str if successful and Null if not
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
toke = str_tok(ptr_copy, ":"); /*changed strtok*/
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
toke = str_tok(NULL, ":"); /*changed strtok*/
}
}
free(ptr_copy);
if (stat(str, &buf) == 0)
{
return (str);
}
return (NULL);
}
return (NULL);
}
