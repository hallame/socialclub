#ifndef MEMBER_H
#define MEMBER_H

struct Member {
    int id;
    char firstName[41]; // 40 caractères max + caractère de fin de chaîne '\0'
    char lastName[41]; // 40 caractères max + caractère de fin de chaîne '\0'
    char city[41]; // 40 caractères max + caractère de fin de chaîne '\0'
    int age;
    int clubCount;
    char clubNames[10][41]; // 10 noms de clubs, chacun avec 40 caractères max + caractère de fin de chaîne '\0'
};

#endif // MEMBER_H

