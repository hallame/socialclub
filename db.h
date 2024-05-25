#ifndef DB_H
#define DB_H

#include "Member.h"
#include <cstddef>
#include <string>

size_t db_size();
void db_read(size_t no, Member* m);
void db_write(size_t no, const Member* m);

#endif // DB_H


