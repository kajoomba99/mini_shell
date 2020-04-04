#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{

	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	read = getline(&line, &len, stdin);
		printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
	return EXIT_SUCCESS;
}
