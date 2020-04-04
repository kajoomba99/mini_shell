#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	ssize_t rgl;
	size_t len = 0;
	char *lineptr;
	pid_t rf1;
	int status;
	char *argv[2];
	argv[1] = NULL;

	do
	{
		printf("#cisfun$ ");

		rgl = getline(&lineptr, &len, stdin);

		strtok(lineptr, "\n");

		argv[0] = lineptr;

		rf1 = fork();

		if (rf1 == 0)
		{
			execve(argv[0], argv, NULL);
			return (1);
		}
		else
		{
			wait(&status);
		}
	} while (rgl != -1);

	return (0);
}