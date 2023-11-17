#include "paskyshell.h"

/**
 * main - a prompt for a user to enter some text and return that same text.
 * the shell will print out Exiting Pasky Simple Shell...
 * right after you click CTRL + D
 *
 * Return:0 on success, 1 on failure
 */

int main(int pc, char **argv)
{
	/* the prompt that is going to show up to the user*/
	char *prompt = "#cisfun$ ";

	/*The getline function*/

	char *lineptr; /* to store the address of the buffer*/
	size_t n = 0; /*Store the allocated size in bytes*/
	ssize_t read_nchars;

	/* declaring void variables because of the flags */
	(void) pc;
	(void) argv;

	/* creating an infinite loop*/

	while (1)
	{
		printf("%s", prompt); /*prints the prompt*/
		read_nchars = getline(&lineptr, &n, stdin);
		/* check if the getline fuction failed or reached EOF or user use CTRL + D*/
		if (read_nchars == -1)
		{
			if (feof(stdin)) /* Check for EOF */
			{
				printf("Exiting pasky shell...\n");
				break; /* Exit the loop on EOF */
			}
			else
			{
				perror(argv[0]); /* Print an error message with the program */
			       exit(EXIT_FAILURE); /* Exit with an error status */
			}
		}
		printf("%s\n", lineptr);
		/* free up allocated memory */
		free(lineptr);
	}
	return (0);
}
