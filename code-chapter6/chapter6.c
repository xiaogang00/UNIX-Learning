# include <sys/types.h>
# include <pwd.h>

//POSIX.1只定义了两个存取口令文件中信息的函数。
struct passwd *getpwuid(uid_t uid);
struct passwd *getpwnam(const char *name);

//如果要查看整个口令文件的内容，可以用以下的三个函数
struct passwd * getpwent(void);
void setpwent(void);
void endpwent(void);

//下面的函数来查看组名或数值组ID
struct group *getgrgid(gid_t gid);
struct group *getgrnam(const char *name);

//登录会计
struct utmp{
    char ut_line[8];
    char ut_name[8];
    long ut_time;
};

//下面的函数返回主机与操作系统有关的
int uname(struct utsname *name) ;

