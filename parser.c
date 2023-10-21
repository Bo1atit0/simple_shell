#include "main.h"

/**
* parse_line - parses the lines into tokens
* @container: a pointer to a structo struct that holds
* the tokens.
*
* desc: This function does the following
* 1. Parses the input string stored in a
* 2. structure and populates a container's parsed field
* 3. with an array of parsed tokens, splitting the input by
* 4. spaces, tabs, and newlines.
*
* Return: 0 if parsing is successful
*/

int parse_line(structo *container)
{
	char *parsed;
	char *dup;
	int x;

	if (!container->input)
	{
		return (1);
	}

	dup = strdup(container->input);

	parsed = str_tok(dup, " \n\t");
	x = 0;
	while (parsed != NULL)
	{
		x++;
		parsed = str_tok(NULL, " \n\t");
	}
	x++;
	free(dup);

	container->parsed = malloc(sizeof(char *) * x);
	parsed = str_tok(container->input, " \n\t");
	if (parsed != NULL)
	{
		for (x = 0; parsed != NULL; x++)
		{
			container->parsed[x] = duplicate(parsed);
			parsed = str_tok(NULL, " \n\t");
		}

		container->parsed[x] = NULL;
	}
	else
	{
		free(container->parsed);
		return (-1);
	}
	return (0);
}

/**
*duplicate - duplicates a string
*@str: string to be duplicated
*
*Description: duplicates a string and returns
*a pointer to the duplicated string
*
*Return: pointer to the duplicated string
*/

char *duplicate(char *str)
{
	char *ptr = malloc(sizeof(char) * strlen(str) + 1);
	int x = 0;
	int y = 0;

	while (str[x])
	{
		ptr[y++] = str[x++];
	}
	ptr[y] = '\0';

	return (ptr);
}

/**
*substitute - substitutes a variable in a string
*
*@str: string whose characters will be replaced
*@call: character string to be duplicated
*
*Description: substitutes a variable in string str with
*a character in call
*
*Return: a pointer to the substituted string
*/

void substitute(char **str, char *call)
{
	free(*str);

	*str = duplicate(call);
}

/**
*converter_to_strings - converts an integer to string
*
*@x: integer to be converted
*@base: base
*
*Description: converts an integer to a string of base
* base and returns a pointer to the converted string
*
* Return: a pointer to the converted string
*/

char *converter_to_strings(long int x, int base)
{
	static char *array = "0123456789abcdef";
	static char arr[50];
	char *str;
	char sym = 0;
	unsigned long num = x;

	if (x < 0)
	{
		num = -x;
		sym = '-';
	}

	str = &arr[49];
	*str = '\0';

	while (num != 0)
	{
		*--str = array[num % base];
		num /= base;
	}

	if (sym == '-')
	{
		*--str = sym;
	}

	return (str);
}
