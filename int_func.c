#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @str: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *str, int base)
{
	int index = 0, is_negative = 0;
	long quotient = number;
	char letters[] = {"0123456789abcdef"};

	if (quotient == 0)
		str[index++] = '0';

	if (str[0] == '-')
		is_negative = 1;

	while (quotient)
	{
		if (quotient < 0)
			str[index++] = letters[-(quotient % base)];
		else
			str[index++] = letters[quotient % base];
		quotient /= base;
	}
	if (is_negative)
		str[index++] = '-';

	str[index] = '\0';
	str_reverse(str);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return (result * sign);
}

/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int count = 0, i = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			count++;
	}
	return (count);
}
