#include "main.h"


/**
*str_tok - tokenizes a string
*@str: string to be tokenized
*@delim: delimeter
*
*Desc: The function iterates through each character
*in the delim string using a while loop.
*it compares the current character
*in the delim string with the character ch provided as a parameter.
*
*Return: pointer to the first token
*
*/

char *str_tok(char *str, const char *delim)
{
static char *token;  /* Use NULL to indicate the initial call*/
char *tok_start;

if (str != NULL)
{
token = str;
}
else if (token == NULL || *token == '\0')
{
return (NULL);  /* No more tokens */
}

/* Skip leading delimiters */
while (*token != '\0' && is_delimiter(*token, delim))
{
token++;
}

if (*token == '\0')
{
return (NULL);  /* No more tokens */
}

tok_start = token;  /* Start of the current token */

/* Find the end of the current token */
while (*token != '\0' && !is_delimiter(*token, delim))
{
token++;
}

if (*token != '\0')
{

*token = '\0';  /* Null-terminate the current token*/
token++;
}

return (tok_start);
}

/**
* is_delimiter - checks if a character is equal to
* a delimiter
*
*@ch: character
*@delim: delimeter
*
*Desc: The function iterates through each character
*in the delim string using a while loop.
*it compares the current character
*in the delim string with the character ch provided as a parameter.
*
*
*
*Return: 0 or 1
*/

int is_delimiter(char ch, const char *delim)
{
while (*delim != '\0')
{
if (ch == *delim)
return (1);
delim++;
}
return (0);
}




