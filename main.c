#include "header.h"


/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @env: An array of environment variable strings.
 *
 * Description: This function is the entry point of the shell program.
 * It initializes the shell and enters the command prompt loop.
 * The shell reads user input, processes commands, and executes them.
 * The program exits when the user enters the "exit" command or
 * presses Ctrl+D (EOF) to indicate the end of input.
 *
 * Return: Always returns EXIT_SUCCESS.
 */

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	cmd_prompt(argv, env);
	return (EXIT_SUCCESS);
}
