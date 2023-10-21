#include "main.h"

/**
*_getline - reads input from file stream
*
*@container: buffer for storing string
*
*Desc: reads input from stdin into a buffer
*of size size and dynamically allocates memory
*
*Return: number of bytes read
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
if (strint[y] == '#' && y != 0)
{
y--;
if (strint[y] == ' ')
{
y++;
strint[y] = '\0';
break;
}
else
{
y++;
}
}
}

container->input = strdup(strint);

free(strint);
return (1);
}

/**
*interactive_or_not - if shell is in interactive mode or not
*
*Description: Checks if the program is running in an interactive terminal.
*
*Return: 1 if in interactive mode 0 if not
*
*/
int interactive_or_not(void)
{
return (isatty(STDIN_FILENO));
}
