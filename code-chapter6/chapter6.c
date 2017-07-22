# include <sys/types.h>
# include <pwd.h>

//POSIX.1只定义了两个存取口令文件中信息的函数。
struct passwd *getpwuid(uid_t uid);
struct passwd *getpwnam(const char *name);

