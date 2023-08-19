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
