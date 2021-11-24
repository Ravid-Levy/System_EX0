#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // we are in child
        // move to root dir used to not block fie system
        chdir("/");
        //move the child to another session so the parent may be close
        setsid();
        printf("startion my daemon\n");
        // close output channels
        close(stdout);
        close(stdin);
        close(stderr);
        // open log
        openlog("myDaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Deamon started 4");
        usleep(3000000);
        syslog(LOG_NOTICE, "Doing some work ..... 4");
        usleep(3000000);

        syslog(LOG_NOTICE, "Deamon Finished 4");
    }
    else
    {
        printf("DAEMON PID %d\n", pid);
    }

    return 0;
}
// search it using
// grep myDaemon /var/log/syslog