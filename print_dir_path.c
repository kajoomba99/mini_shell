#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);
void print_dir_path(char *directories);

int main()
{
	char *directories = _getenv("PATH");
	print_dir_path(directories);
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *key;
	char *dup = strdup(name);
	char *value;
	char *token;

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(dup, environ[i]) == 0)
		{
			key = token;
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	return (value);
}

void print_dir_path(char *directories)
{
	char *token = strtok(directories, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}