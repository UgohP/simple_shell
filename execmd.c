#include "paskyshell.h"
#include <sys/wait.h>
#include <unistd.h>

/**
 * execmd - execute commands
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: Always 0
 */
void execmd(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("./hsh: Error");
		exit(1);
	} else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	} else
	{
		perror("./hsh: Error");
	}
}
