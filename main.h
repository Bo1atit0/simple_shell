#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>


/**
 * struct formation - my container
 * @input: a pointer to the input from user
 * @parsed: parsed input
 * @inst: instrunctions
 * @exit: exitstatus
 * @args: arguments
 */
typedef struct formation
{
char *input;
char **parsed;
char *inst;
int exit;
int args;
} structo;


/**
 * struct specifiers - for builtins
 * @symbol: symbol
 * @func: function
 */
typedef struct specifiers
{
char *symbol;
int (*func)(structo *, char **);
} spec;

/** for prompt.c **/
int hsh(int, char **, char **);
int commence(char *str, char *ptr);
char *command(char **env, char *str);
char *env_opt(char **env, char *str);

/** get_input.c **/
int _getline(structo *);
int interactive_or_not(void);

/** my_builtins.c **/
int _my_env(structo *container, char **env);
int specifiers(structo *container, char **env);
int _my_exit(structo *container, char **env);


/** shell_commands.c **/
void shell_loop(structo *container, char **env);
int executor(int, char **, structo *, char **);
int found_command(structo *container, char **env);
void for_parsed(structo *container, char **env);


/** parser.c **/
int parse_line(structo *);
void freer_for_parser(structo *);
char *duplicate(char *str);
void substitute(char **str, char *call);
char *converter_to_strings(long int x, int base);


int _atoi(char *s);
void our_puts(char *str);
char *our_strdup(char *str);
size_t our_strlen(const char *s);
int is_delimiter(char ch, const char *delim);


char *our_strtok(char *str, char *delim);
ssize_t our_getline(char **storage, size_t *size, FILE *stream);
#endif
