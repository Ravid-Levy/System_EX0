#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define stack_size 10000
#define cycles 1000
char child_stack[stack_size + 1];
char child_stack2[stack_size + 1];

void print(const char *text)
{
    int i;
    for (i = 0; i < cycles; i++)
    {
        printf("Hello from %s\n", text);
        usleep(1000000);
    }
}

int child(void *params)
{
    print("child thread");
}

int main()
{

    int result = clone(child, child_stack + stack_size, CLONE_PARENT, 0);
    int result2 = clone(child, child_stack2 + stack_size, CLONE_PARENT, 0);

    printf("clone result =%d\n", result);
    printf("clone2 result =%d\n", result);

    print("parent");
    return 0;
}