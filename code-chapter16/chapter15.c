#include "db.h"
DB *db_open(const char* pathname, int oflag, int mode);
void db_close(DB * db);

//向数据库中加入数据
int db_store(DB * db,const char * key, const char * data, int flag);
//返回：若成功则为0，若错误则为非0(见下)

//通过提供关键字key可以从数据库中取出一条记录
char *db_fetch(DB * db,const char * key) ;
//返回：若成功则为指向数据的指针，若记录没有找到则为NULL

//通过提供关键字key，也可以从数据库中删除一条记录
int db_delete(DB * db,const char * key) ;
//返回：若成功则为0， 若记录没有找到则为 - 1

//首先调用db_rewind回到数据库的第一条记录，再调用 db_nextrec顺序地读每个记录
void db_rewind(DB * db);
char *db_nextrec(DB * db, char* key);
//返回：若成功则返回指向数据的指针，若到达数据库的尾端则为NULL

