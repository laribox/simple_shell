#include "header.h"

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
 * _strstr - Locates a substring within a string.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}

	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}

/**
 * _strdup - Duplicates a string.
 * @src: The source string to duplicate.
 *
 * Return: A pointer to the duplicated string (allocated memory),
 * or NULL if memory allocation fails or src is NULL.
 */
char *_strdup(const char *src)
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
		return (NULL);
	}

	return (dest);
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 * Return: A pointer to the destination string `dest`.
 */
char *_strcat(char *dest, const char *src)
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
 * _strcpy - Copy a string.
 * @dest: The destination string.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string `dest`.
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}

	*temp = '\0';
	return (dest);
}
