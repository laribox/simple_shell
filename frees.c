#include "shell.h"



/**
 * release_all_data - Frees all fields of the program's data.
 * @data: Struct containing the program's data.
 * Return: Nothing.
 */
void release_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	release_recurrent_data(data);
	free_pointer_array(data->env);
}

/**
 * free_pointer_array -Frees each pointer
 *	in an array of pointers and the array itself.
 * @array: Array of pointers.
 * Return: Nothing.
 */
void free_pointer_array(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

/**
 * release_recurrent_data - Frees the fields needed for each loop iteration.
 * @data: Struct containing the program's data.
 * Return: Nothing.
 */
void release_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_pointer_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}
