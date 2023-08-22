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

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to,
 *      or greater than 0 if s1 is found, respectively,
 *      to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int)(*s1) - (int)(*s2));
}

/**
 * _strspn - Calculates the length of a prefix substring
 *          that only contains characters from a specified set.
 * @str1: The input string whose substring's length is to be calculated.
 * @str2: The set of characters that are allowed in the substring.
 *
 * Return: The length of the initial substring in str1
 *          consisting of characters only from str2.
 */
int _strspn(const char *str1, const char *str2)
{
	int length = 0;

	while (*str1)
	{
		const char *temp = str2;
		int found = 0;


		while (*temp)
		{
			if (*temp == *str1)
			{
				found = 1;
				break;
			}
			temp++;
		}

		if (!found)
		{
			break;
		}

		str1++;
		length++;
	}

	return (length);
}


/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero
 * if s1 is found, respectively, to be less than, to match, or
 * be greater than s2.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		if (s1[i] == '\0')
		{
			break;
		}
	}

	return (0);
}


/**
 * _itoa - converts an integer to a string
 * @num: the integer to convert
 * @str: buffer to store the resulting string
 */
void _itoa(int num, char *str)
{
	int i = 0;
	int is_negative = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num > 0)
	{
		int digit = num % 10;

		str[i++] = digit + '0';
		num /= 10;
	}
	if (is_negative)
		str[i++] = '-';

	str[i] = '\0';

	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
