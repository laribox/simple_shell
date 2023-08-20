#include "header.h"

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
