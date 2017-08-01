#include "db.h"
DB *db_open(const char* pathname, int oflag, int mode);
void db_close(DB * db);

