#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


/* Resume from the unused attibute */
#define UNUSED __attribute__((unused))

/* buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/* Prompt to be printed */
#define PROMPT_MSG "$ " /* Needed to work with signal */

/**
 * struct shell_info - struct for the shell data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 */
typedef struct shell_info
{
	char *program_name;
	char *command_name;
	char *input_line;
	int file_descriptor;
	int exec_counter;
	char **tokens;
	char **env;
} data_of_program;

/*========  main.c  ========*/
void initialize_data(data_of_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_of_program *data);

/*========  utils.c  ========*/
int _getline(data_of_program *data);
char *_strtok(char *line, char *delim);
void tokenize(data_of_program *data);
void handle_ctrl_c(int opr UNUSED);

/*======== execute_cmd.c ========*/
int run_executable(data_of_program *cmd_data);

/*======== search_path.c ========*/
char **get_directories(data_of_program *data);
int find_program(data_of_program *data);
int check_file_exists(char *full_path);
/*======== frees.c ========*/
void free_pointer_array(char **directories);
void release_recurrent_data(data_of_program *data);
void release_all_data(data_of_program *data);

/*======== builtins.c ========*/
int builtins(data_of_program *data);
int _exit_shell(data_of_program *data);
int _env(data_of_program *data);
char *env_get_key(char *name, data_of_program *data);

/*======== printers.c ========*/
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);

/*======== str_func.c ========*/
int _strlen(char *s);
char *str_duplicate(char *src);
int str_compare(char *string1, char *string2, int number);
char *_strcat(char *string1, char *string2);
void str_reverse(char *string);

/*======== int_func.c ========*/
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);


#endif /* SHELL_H */
