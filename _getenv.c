#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

int main(int ac, char **av)
{
	char *rge = _getenv(av[1]);
	if (rge != NULL)
	{
		printf("%s\n", rge);
	}
	else
	{
		printf("Not found\n");
	}
	return (0);
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *dup = strdup(name);
	char *value = NULL;
	char *token;

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(dup, environ[i]) == 0)
		{
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	if (!value)
		return NULL;

	return (value);
}