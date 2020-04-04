#include <stdio.h>
#include <unistd.h>

int main()
{
	if(access("/bin/ls", F_OK) == 0)
	{
		printf("Found %s\n", "/bin/ls");
	}
	else
	{
		printf("Not found %s\n", "/bin/ls");
	}
	
	return (0);
}