//下列三个函数可以用于打开一个标准I/O流
# include <stdio.h>
FILE *fopen(const char *pathname, const char *type);
FILE *freopen(const char *pathname, const char *type, FILE *fp);
FILE *fdopen(int filedes, const char *type);
//三个函数的返回：如果成功则为文件指针，出错则为NULL

int getc(FILE *fp);
int fgetc(FILE *fp);
int getchar(void);

int ferror(FILE *fp);
int feof(FILE *fp);
void clearerr(FILE *fp);

//输出函数
int putc(int c, FILE *fp);
int fputc(int c, FILE *fp);
int putchar(int c);

//下面两个函数提供每次输入一行的功能
char *fgets(char *buf, int n, FILE *fp);
char *getc(char *buf);

//二进制I/O
size_t fread(void *ptr, size_t size, size_t nobj, FILE *fp);
size_t fwrite(const void *ptr, size_t size, size_t nobj, FILE *fp);

//格式化I/O
//格式化输出
int printf(const char *format, ...);
int fprintf(FILE *fp, const char *format, ...);
int sprintf(char *buf, const char *format, ...);

//格式化输入
int scanf(const char *format, ...);
int fscanf(FILE *fp, const char *format, ...);
int sscanf(const char *buf, const char *format, ...);


