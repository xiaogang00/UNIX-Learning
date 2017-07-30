#include <stdio.h>
FILE *popen(const char * cmdstring, const char * type) ;
//返回：若成功则为文件指针，若出错则为 N U L L

int pclose(FILE * fp) ;
//返回： cmdstring的终止状态，若出错则为-1

