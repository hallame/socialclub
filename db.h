#ifndef DB_H
#define DB_H

#include "Member.h"
#include <cstddef>
#include <string>

size_t db_size();
void db_read(size_t no, Member* m);
void db_write(size_t no, const Member* m);


//
// // Écrit un membre à une position spécifique dans le fichier de base de données
// void db_write(size_t pos, const Member* member);
//
// // Lit un membre d'une position spécifique dans le fichier de base de données
// void db_read(size_t pos, Member* member);
//
// // Retourne le nombre de membres dans la base de données
// size_t db_size(const std::string& dbFile);

//
// size_t db_size(const std::string& filename);
// void db_read(const std::string& filename, size_t index, Member* m);
// void db_write(const std::string& filename, size_t index, const Member* m);



#endif // DB_H


