# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int open(const char *pathname, int oflag,... /*, mode_t mode */);

int creat(const char *pathname, mode_t mode);

int close(int filedes);

off_t lseek(int filedes, off_t offset, int whence);

//例子：测试标准输入能否被设置位移量
# include "ourhdr.h"
int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else 
        printf("seek OK \n");
    exit(0);
}

//创建一个具有空洞的文件
# include <fcntl.h>
# include "ourhdr.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    if ((fd == creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");
    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    if (lseek(fd, 40, SEEK_SET) == -1)
        err_sys("lseek error");
    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    exit(0);
}

# include <unistd.h>
ssize_t read(int filedes, void * buff, size_t nbytes);
ssize_t write(int filedes, const void * buff, size_t nbytes);

//将标准输入复制到标准输出
#define BUFFSIZE 8192
int main(void)
{
    int n;
    char buf[BUFFSIZE];
    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
       if (write(STDOUT_FILENO, buf, n) != n)
          err_sys("write error");
    if (n < 0)
       err_sys("read error");
    exit(0);
}

//dup和dup2函数
int dup(int filedes);
int dup2(int filedes, int filedes2);

