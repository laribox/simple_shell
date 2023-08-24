#include "shell.h"
/**
 * main - Start the program
 * @argc: count of argv
 * @argv: values received from the command line
 * @env: envirement
 * Return: zero.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	initialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	inter_loop(prompt, data);
	return (0);
}

/**
 * initialize_data - Initialize the program's data structure.
 * @data: Pointer to the data structure.
 * @argc: Array of arguments provided during program execution.
 * @argv: values received from the command line.
 * @env: Environment variables provided during program execution.
 */
void initialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;
}

/**
 * inter_loop - its a infinite loop that shows the prompt
 * @prompt: prompt to be printed
 * @data: its a infinite loop that shows the prompt
 */
void inter_loop(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			release_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			tokenize(data);
			if (data->tokens[0])
			{
				error_code = run_executable(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			release_recurrent_data(data);
		}
	}
}
