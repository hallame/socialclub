#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <cstring>

constexpr size_t MAX_STRING_LENGTH = 41; // Taille maximale des chaînes de caractères (40 caractères + '\0')

struct Club {
    char name[MAX_STRING_LENGTH]; // Nom du club (40 caractères + '\0')
};

struct Member {
    char firstName[MAX_STRING_LENGTH]; // Prénom du membre (40 caractères + '\0')
    char lastName[MAX_STRING_LENGTH]; // Nom du membre (40 caractères + '\0')
    char city[MAX_STRING_LENGTH]; // Ville du membre (40 caractères + '\0')
    int age; // Age du membre (entre 16 et 120 ans)
    int clubCount; // Nombre actuel de clubs (entre 0 et 10)
    char clubNames[10][MAX_STRING_LENGTH]; // Liste des noms des clubs (10 clubs, chaque nom a une taille maximale de 40 caractères + '\0')
};

#endif // STRUCTURES_H
