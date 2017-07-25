#include <sys/types.h>
#include <fcntl.h>
#include "ourhdr.h"

//加锁和解锁一个文件区域的函数
int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
    struct flock  lock;
    lock.l_type = type;
    lock.l_start = offset;
    lock.l_whence = whence;
    lock.l_len = len;
    return (fcntl(fd, cmd, &lock));
}

//测试一个锁条件的函数
#define is_readlock(fd, offset, whence, len) lock_test(fd, F_RDLCK, offset, whence, len)
#define is_writelock(fd, offset, whence, len) lock_test(fd, F_WRLCK, offset, whence, len)

//死锁检测实例
int main(void)
{
    int fd;
    pid_t pid;
    if((fd = creat("templock", FILE_MODE)) < 0)
       err_sys("creat error");
    if(write(fd, "ab", 2) != 2)
       err_sys("write error");
    TELL_WAIT();
    if((pid = fork()) < 0)
       err_sys("fork error");
    else if(pid == 0)
    {
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    }
    else
    {
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte('parent', fd, 0);
    }
    exit(0);
}
static void lockabyte(const char *name, int fd, off_t offset)
{
    if(writew_lock(fd, offset, SEEK_SET, 1) < 0)
       err_sys("%s: writew_lock error", name);
    printf("%s: got the lock, byte %d \n", name, offset);
}

