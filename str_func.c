#include "shell.h"


/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to a string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * str_duplicate - duplicates an string
 * @src: String to be copied
 * Return: pointer to the array
 */
char *str_duplicate(char *src)
{
	size_t len = 0, i;
	char *dest;

	if (src == NULL)
		return (NULL);

	while (src[len] != '\0')
	{
		len++;
	}
	len++;
	dest = (char *)malloc(len);

	if (dest != NULL)
	{
		for (i = 0; i < len; i++)
		{
			dest[i] = src[i];
		}
	}
	else
	{
		free(dest);
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	return (dest);
}

/**
 * str_compare - Compare two strings
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int str_compare(char *s1, char *s2, int number)
{
	int iterator = 0;

	if (s1 == NULL && s2 == NULL)
		return (0);

	if (s1 == NULL || s2 == NULL)
		return (1);


	while (number == 0 || iterator < number)
	{
		if (*s1 != *s2)
			return (0);

		if (*s1 == '\0')
			return (1);

		s1++;
		s2++;
		iterator++;
	}

	return (1);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 * Return: A pointer to the destination string `dest`.
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*temp)
		temp++;

	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}

	*temp = '\0';
	return (dest);
}


/**
 * str_reverse - reverses a string.
 *
 * @string: pointer to string.
 * Return: void.
 */
void str_reverse(char *string)
{

	int i = 0, length = _strlen(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
