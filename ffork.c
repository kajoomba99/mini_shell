#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t my_pid2;
    pid_t child_pid;
    pid_t child_pid2;
    pid_t child_pid3;

    child_pid = fork();
    
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    my_pid2 = getpid();
    printf("My pid2 is %u\n", my_pid2);
    if (child_pid == 0)
    {
        printf("(%u) Nooooooooo!\n", my_pid);
    }
    else
    {
        printf("(%u) I am your father\n", my_pid);
    }
    return (0);
}