//初始化一个精灵进程
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ourhdr.h"

int daemon_init(void)
{
    pid_t pid;
    if((pid = fock()) < 0)
       return (-1);
    else if(pid != 0)
       exit(0);
    setsid();
    chdir("/");
    umask(0);
    return(0);
}


