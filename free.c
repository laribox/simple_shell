#include "header.h"



/**
 * free_argv - Frees the memory allocated for an array of strings.
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
