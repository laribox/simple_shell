#include "shell.h"

/**
 * run_executable - Execute a command with its path variables.
 * @cmd_data: A pointer to the command's data.
 * Return: If successful, returns zero. Otherwise, returns -1.
 */
int run_executable(data_of_program *cmd_data)
{
	int ret_value = 0, status;
	pid_t child_pid;

	ret_value = builtins(cmd_data);
	if (ret_value != -1)
		return (ret_value);

	ret_value = find_program(cmd_data);
	if (ret_value)
	{
		return (ret_value);
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(cmd_data->command_name);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			ret_value = execve(cmd_data->tokens[0], cmd_data->tokens, cmd_data->env);
			if (ret_value == -1)
				perror(cmd_data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}

