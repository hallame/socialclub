
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
