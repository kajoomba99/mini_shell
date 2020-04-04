#include <stdio.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;
	printf("%p\n%p\n", &(*env), &(*environ));

	return (0);
}