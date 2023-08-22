#include "header.h"

/**
 * _print - writes string to the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
 * _print_error - writes string to the standar error
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */

int _print_error(char *string)
{
	return (write(STDERR_FILENO, string, _strlen(string)));
}


/**
 * print_custom_error - prints a custom error message
 * @cmd_name: the name of the command (argv[0])
 * @counter: the command counter
 * @error_msg: the error message to be printed
 */
void print_custom_error(char *cmd_name, int counter, char *error_msg)
{
	char counter_str[20];

	_itoa(counter, counter_str);

	_print_error(cmd_name);
	_print_error(": ");
	_print_error(counter_str);
	_print_error(": ");
	_print_error(error_msg);
}
