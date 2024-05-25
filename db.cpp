
#include "db.h"
#include <fstream>
#include <iostream>


const std::string DB_FILENAME = "clubsocial.db";

size_t db_size() {
    std::ifstream file(DB_FILENAME, std::ios::binary | std::ios::ate);
    if (!file) {
        return 0;
    }
    return file.tellg() / sizeof(Member);
}


void db_read(size_t no, Member* m) {
    std::ifstream file(DB_FILENAME, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Couldn't open database file for reading." << std::endl;
        return;
    }
    file.seekg(no * sizeof(Member));
    file.read(reinterpret_cast<char*>(m), sizeof(Member));
}

void db_write(size_t no, const Member* m) {
    std::fstream file(DB_FILENAME, std::ios::binary | std::ios::in | std::ios::out);
    if (file) {
        file.seekp(no * sizeof(Member));
        file.write(reinterpret_cast<const char*>(m), sizeof(Member));
    } else {
        std::ofstream outFile(DB_FILENAME, std::ios::binary);
        outFile.seekp(no * sizeof(Member));
        outFile.write(reinterpret_cast<const char*>(m), sizeof(Member));
    }
}




//
// size_t db_size(const std::string& filename) {
//     std::ifstream file(filename, std::ios::binary | std::ios::ate);
//     if (!file) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier de base de donnees" << std::endl;
//         return 0;
//     }
//     return file.tellg() / sizeof(Member);
// }
//
// void db_read(const std::string& filename, size_t index, Member* m) {
//     std::ifstream file(filename, std::ios::binary);
//     if (!file) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier de base de donnees pour la lecture." << std::endl;
//         return;
//     }
//     file.seekg(index * sizeof(Member));
//     file.read(reinterpret_cast<char*>(m), sizeof(Member));
// }
//
// // void db_write(const std::string& filename, size_t index, const Member* m) {
// //     std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
// //     if (!file) {
// //         file.open(filename, std::ios::binary | std::ios::out);
// //     }
// //     if (!file) {
// //         std::cerr << "Erreur : Impossible d'ouvrir le fichier de base de donnees pour l'ecriture." << std::endl;
// //         return;
// //     }
// //     file.seekp(index * sizeof(Member));
// //     file.write(reinterpret_cast<const char*>(m), sizeof(Member));
// // }
//
// void db_write(size_t index, const Member* member) {
//     std::fstream file("clubsocial.db", std::ios::binary | std::ios::in | std::ios::out);
//     if (file) {
//         file.seekp(index * sizeof(Member));
//         file.write(reinterpret_cast<const char*>(member), sizeof(Member));
//     } else {
//         std::ofstream outFile("clubsocial.db", std::ios::binary);
//         outFile.seekp(index * sizeof(Member));
//         outFile.write(reinterpret_cast<const char*>(member), sizeof(Member));
//     }
// }





// void db_write(size_t pos, const Member* member) {
//     std::ofstream dbFile("clubsocial.db", std::ios::binary | std::ios::in | std::ios::out);
//     if (!dbFile) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier de base de données pour l'écriture." << std::endl;
//         return;
//     }
//     dbFile.seekp(pos * sizeof(Member));
//     dbFile.write(reinterpret_cast<const char*>(member), sizeof(Member));
//     dbFile.close();
// }
//
// void db_read(size_t pos, Member* member) {
//     std::ifstream dbFile("clubsocial.db", std::ios::binary);
//     if (!dbFile) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier de base de données pour la lecture." << std::endl;
//         return;
//     }
//     dbFile.seekg(pos * sizeof(Member));
//     dbFile.read(reinterpret_cast<char*>(member), sizeof(Member));
//     dbFile.close();
// }
//
// size_t db_size(const std::string& filename) {
//     std::ifstream file(filename, std::ios::binary | std::ios::ate);
//     return file ? file.tellg() / sizeof(Member) : 0;
// }
