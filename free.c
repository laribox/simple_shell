#include "header.h"



/**
 * free_args - Frees the memory allocated for an array of strings.
 * @argv: The array of strings to be freed.
 *
 * Description: This function frees the memory allocated for each string
 * in the input array of strings (argv) and then frees the memory allocated
 * for the array itself. It sets the pointers to NULL after freeing to
 * prevent dangling pointers. If argv is NULL, no action is taken.
 */
void free_args(char *argv[])
{
	if (argv == NULL)
		return;

	for (int i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
		argv[i] = NULL;
	}
}


/**
 * _exit_shell - Clean up and exit the shell if the exit command is given.
 * @cmd: The command string to free.
 * @args: The argument array to free.
 */
void _exit_shell(char *cmd, char *args[])
{
	if (_strcmp(cmd, "exit") == 0)
	{
		free_args(args);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}
