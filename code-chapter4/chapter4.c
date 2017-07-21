# include <sys/types.h>
# include <sys/stat.h>

int stat(const char *pathname, struct stat * buf);
int fstat(int filedes, struct stat * buf);
int lstat(const char * pathname, struct stat * buf);

struct stat{
    mode_t st_mode;
    ino_t st_ino;
    dev_t st_dev;
    dev_t st_rdev;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
    long st_blksize;
    long st_blocks;
}



//对每个命令行参数打印文件类型
# include <sys/types.h>
# include <sys/stat.h>
# include "ourhdr.h"

int main(int argc, char * argv[])
{
    int i;
    struct stat buf;
    char *ptr;
    for (int i = 1; i < argc ; i++){
        printf("%s: ", argv[i]);
        if(lstat(argv[i], &buf) < 0){
            err_ret("lstat error");
            continue
        }
        if (S_ISREG(buf.st_mode)) ptr = "regular";
        else if (S_ISDIR(buf.st_mode)) ptr = "directory";
        else if (S_ISCHR(buf.st_mode)) ptr = "character special";
        else if (S_ISBLK(buf.st_mode)) ptr = "block special";
    }
    exit(0);
}

mode_t umask(mode_t cmask);
//参数cmake由表4 - 4中的9个常数( S_IRUSR , S_IWUSR等)逐位“或”构成的
int chown(const char *pathname, uid_t owner, gid_t group);
int fchown(int filedes, uid_t owner, gid_t group);
int lchown(const char *pathname, uid_t owner, gid_t group);



