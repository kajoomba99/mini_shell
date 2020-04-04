#include <stdio.h>

int main(int ac, char **av, char **env)
{
	for (size_t i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}	
}