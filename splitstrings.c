#include "paskyshell.h"
#include <string.h>

/**
 * line_split - Split strings
 *
 * @lineptr: Pointer string from the getline
 * This function takes a string obtained from getline and splits it into tokens
 * based on the specified delimiters (whitespace characters).
 *
 * Return: Always 0
 */

char **line_split(char *lineptr)
{
	int i = 0;
	int memory  = 16;
	char **tokens = malloc(memory * sizeof(char *));
	char *delim = " \t\r\n";
	char *token = strtok(lineptr, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= memory)
		{
			memory = (int) (memory * 1.5);
			tokens = realloc(tokens, memory * sizeof(char *));
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
