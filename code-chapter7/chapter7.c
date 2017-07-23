# include <stdlib.h>
void exit(int status);
void _exit(int status);

//终止处理程序实例
# include "ourhdr.h"
static void my_exit1(void), my_exit2(void);

int main(void){
    if (atexit(my_exit2) != 0)
       err_sys("can't register my_exit2");
    if (atexit(my_exit1) != 0)
       err_sys("can't register my_exit1");
    printf("main is done\n");
    return(0);
}
static void my_exit1(void)
{
    printf("first exit handler\n");
}
static void my_exit2(void)
{
    printf("second exit handler\n");
}

//三个用于存储空间动态分配
void *malloc(size_t size);
void *calloc(size_t *obj, size_t size);
void *realloc(void *ptr, size_t newsize);
void free(void *ptr);

//获取环境变量值
char *getenv(const char *name);
//设置环境变量
int putenv(const char *str);
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name);

//跳转的函数
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

//获取资源限制的函数
int getrlimit(int resource, struct rlimit *rlptr);
int setrlimit(int resource, const struct rlimit *rlptr);
