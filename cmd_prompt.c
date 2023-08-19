#include "header.h"

/**
 * cmd_prompt - Implements a simple shell prompt.
 * @argv: Array of strings containing command-line arguments.
 * @env: Array of strings containing environment variables.
 *
 * Description: Displays a shell prompt, reads user input,
 * and executes the entered command using execve.
 */
void cmd_prompt(char *argv[], char *env[])
{
	char *cmd = NULL;
	size_t n = 0;
	char *args[] = {NULL, " /var", " -l", NULL};
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			_print("#cisfun$ ");

		ssize_t size = getline(&cmd, &n, stdin);

		if (size == -1)
		{
			if (feof(stdin))
			{
				free(cmd);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}

		remove_newline(cmd);

		args[0] = cmd;
		execute_and_wait(args, env, argv);
	}
}

/**
 * remove_newline - Removes the newline character from a string.
 * @str: The string to modify.
 *
 * Description: Modifies the input string in place by replacing
 * the newline character with a null terminator.
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
}


/**
 * execute_and_wait - Forks a child process,
 * executes a command, and waits for the child to complete.
 * @args: Array of strings containing the command and arguments.
 * @env: Array of strings containing environment variables.
 * @argv: Array of strings containing command-line arguments.
 */
void execute_and_wait(char *args[], char *env[], char *argv[])
{
	pid_t new_pro;
	int status;

	new_pro = fork();
	if (new_pro == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (new_pro == 0)
	{
		execute_command(args, env, argv);
	}
	else
	{
		wait(&status);
	}
}

/**
 * execute_command - Executes a command using execve.
 * @args: Array of strings containing the command and its arguments.
 * @env: Array of strings containing environment variables.
 * @argv: Array of strings containing command-line arguments.
 *
 * Description: Executes the command specified in the args array
 * using the execve system call. Prints an error message if the
 * command execution fails.
 */
void execute_command(char *args[], char *env[], char *argv[])
{
	if (execve(args[0], args, env) == -1)
	{
		_print_error(argv[0]);
		_print_error(": No such file or directory\n");
		exit(EXIT_FAILURE);
	}
}
