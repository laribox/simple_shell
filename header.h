#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> /* printf*/
#include <unistd.h> /* fork, execve*/
#include <stdlib.h>
#include <string.h> /* strtok*/
#include <stddef.h>
#include <errno.h> /*  errno and perror */
#include <sys/types.h> /* type pid */
#include <sys/wait.h> /* wait */
#include <sys/stat.h> /* stat function */
#include <signal.h> /* signal management */
#include <fcntl.h> /* open files*/


/* printing functions */
int _print(char *string);
int _print_error(char *string);


/* prompt executing function */
void cmd_prompt(char *argv[], char *env[]);
void execute_command(char *command, char *args[], char *env[]);
void execute_and_wait(char *args[], char *env[], char *argv[]);
void tokenize_command(char *command, char *args[]);
char *search_command(char *command);

/* str_func_1 */
void remove_newline(char *str);
int _strcmp(const char *s1, const char *s2);
int _strspn(const char *str1, const char *str2);

/* free */
void free_args(char *argv[]);

/* string mapulation functions */
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strdup(const char *src);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

#endif /* HEADER_H */
