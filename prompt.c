#include <stdio.h>
#include <stdlib.h>

int main()
{
	ssize_t nread;
	size_t len = 0;
	char *line;

	do {
		putchar('$');
		putchar(' ');
		nread = getline(&line, &len, stdin);
		printf("%s",line); 
	} while (nread != -1);

	return (EXIT_SUCCESS);
}
