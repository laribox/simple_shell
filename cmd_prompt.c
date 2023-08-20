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
	char *args[] = {NULL, NULL, NULL};
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
				free_args(args);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free_args(args);
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}

		remove_newline(cmd);
		tokenize_command(cmd, args);
		execute_and_wait(args, env, argv);
		free_args(args);
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


/**
 * tokenize_command - Tokenizes a command string into an array of strings.
 * @command: The command string to tokenize.
 * @args: An array of strings to store the tokenized command.
 *
 * Description: This function splits the input command string into tokens
 * using space characters as delimiters. Each token is dynamically allocated
 * using strdup and stored in the args array. The last element of the args
 * array is set to NULL to indicate the end of the array. If memory allocation
 * fails, an error message is printed and the program exits with EXIT_FAILURE.
 */
void tokenize_command(char *command, char *args[])
{
	char *token = strtok(command, " ");

	int index = 0;

	while (token != NULL)
	{
		args[index] = _strdup(token);

		if (args[index] == NULL)
		{
			perror("strdup");
			free_args(args);
			exit(EXIT_FAILURE);
		}

		index++;
		token = strtok(NULL, " ");
	}

	args[index] = NULL;
}

/**
 * search_command - Search for an executable command in the directories
 *          listed in the PATH environment variable.
 * @command: The name of the command to search for.
 *
 * Return: A dynamically allocated string containing the full path
 *         to the executable command if found,
 *         or NULL if the command was not found in any of the directories.
 */
char *search_command(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");
	char *full_path = NULL;

	while (path != NULL)
	{
		full_path = (char *)malloc(strlen(path) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_strcpy(full_path, path);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}

	return (NULL);
}
