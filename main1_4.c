#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char Programs[] = "./main1_#";

int main()
{
    printf("my pid %d\n", getpid());

    for (size_t i = 0; i < 3; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            Programs[strlen(Programs) - 1] = '1' + i;
            printf("Start %s Program \n", Programs);
            char *args[2] = {Programs, NULL};
            execvp(args[0], args);
        }
    }
    sleep(12);
    while (wait(NULL) > 0)
    {
    }
    printf("all child processes are closed...\n");
    return 0;
}