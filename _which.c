#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	struct stat st;
	char ruta[100];
	getcwd(ruta, 100);
	strcat(ruta, "/");
	strcat(ruta, av[1]);
	if (stat(ruta, &st) == 0)
	{
		printf("%s\n", ruta);
	}
	else
	{
		printf("NOT FOUND\n");
	}
	return (0);
}