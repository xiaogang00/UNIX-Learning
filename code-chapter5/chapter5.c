//下列三个函数可以用于打开一个标准I/O流
# include <stdio.h>
FILE *fopen(const char *pathname, const char *type);
FILE *freopen(const char *pathname, const char *type, FILE *fp);
FILE *fdopen(int filedes, const char *type);
//三个函数的返回：如果成功则为文件指针，出错则为NULL
