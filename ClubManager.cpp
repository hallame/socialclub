#include "ClubManager.h"
#include "db.h"
#include <iostream>
#include <fstream>
#include <cstring>


ClubManager::ClubManager() : memberCount(0), clubCount(0) {}

ClubManager::~ClubManager() {
    clearAllMembers();
    clearAllClubs();
}

void ClubManager::addMember(const Member& member) {
    if (memberCount < MAX_MEMBERS) {
        members[memberCount] = member;
        members[memberCount].id = memberCount + 1; // Assigner un ID
        memberCount++;
    } else {
        std::cerr << "Erreur : Nombre maximal de membres atteint." << std::endl;
    }
}
//
// void ClubManager::addMember(const Member& member) {
//     if (memberCount < MAX_MEMBERS) {
//         members[memberCount++] = member;
//     } else {
//         std::cerr << "Erreur : Nombre maximal de membres atteint." << std::endl;
//     }
// }

Member ClubManager::getMember(int id) const {
    for (int i = 0; i < memberCount; ++i) {
        if (members[i].id == id) {
            return members[i];
        }
    }
    // Retourne un membre avec un ID invalide si aucun membre n'est trouvé
    return Member{-1, "", "", "", 0, 0, {""}};
}

void ClubManager::displayMembers() const {
    for (int i = 0; i < memberCount; ++i) {
        std::cout << "Membre " << members[i].id << ": " << members[i].firstName << " " << members[i].lastName << std::endl;
        // Afficher d'autres informations sur le membre si nécessaire
    }
}

void ClubManager::removeMember(int memberId) {
    for (int i = 0; i < memberCount; ++i) {
        if (members[i].id == memberId) {
            // Décaler les membres suivants pour remplir le trou
            for (int j = i; j < memberCount - 1; ++j) {
                members[j] = members[j + 1];
            }
            memberCount--; // Mettre à jour le compteur de membres
            std::cout << "Membre supprimé avec succès." << std::endl;
            return;
        }
    }
    std::cerr << "Erreur : Membre non trouvé." << std::endl;
}

void ClubManager::addClub(const Club& club) {
    if (clubCount < MAX_CLUBS) {
        clubs[clubCount] = club;
        //clubs[clubCount] = new Club(club); // Allouer dynamiquement un nouvel objet Club
        clubCount++;
    } else {
        std::cerr << "Erreur : Nombre maximal de clubs atteint." << std::endl;
    }
}

void ClubManager::removeClub(const std::string& clubName) {
    for (int i = 0; i < clubCount; ++i) {
        if (std::strcmp(clubs[i].name, clubName.c_str()) == 0) {
            // Décaler les clubs suivants pour remplir le trou
            for (int j = i; j < clubCount - 1; ++j) {
                clubs[j] = clubs[j + 1];
            }
            clubCount--; // Mettre à jour le compteur de clubs
            std::cout << "Club supprimé avec succès." << std::endl;
            return;
        }
    }
    std::cerr << "Erreur : Club non trouvé." << std::endl;
}

void ClubManager::clearAllMembers() {
    memberCount = 0;
}

void ClubManager::clearAllClubs() {
    clubCount = 0;
}

// size_t ClubManager::getClubCount() const {
//     return clubCount;
// }
//
// Club* ClubManager::getClubs() const {
//     return *clubs;
// }


//
// ClubManager::ClubManager() : clubCount(0) {}
//
// ClubManager::~ClubManager() {
//     clearAllMembers();
//     clearAllClubs();
// }
//
// void ClubManager::addMember(const Member& member) {
//     size_t index = db_size("clubsocial.db");
//     db_write("clubsocial.db", index, &member);
// }
//
// Member ClubManager::getMember(size_t index) const {
//     Member member;
//     db_read("clubsocial.db", index, &member);
//     return member;
// }
//
// size_t ClubManager::getMemberCount() const {
//     return db_size("clubsocial.db");
// }
//
// void ClubManager::displayMembers() const {
//     size_t memberCount = getMemberCount();
//     for (size_t i = 0; i < memberCount; ++i) {
//         Member member = getMember(i);
//         std::cout << "Membre " << i + 1 << ": " << member.firstName << " " << member.lastName << std::endl;
//     }
// }
//
// void ClubManager::removeMember(size_t index) {
//     size_t memberCount = getMemberCount();
//     for (size_t i = index; i < memberCount - 1; ++i) {
//         Member member = getMember(i + 1);
//         db_write("clubsocial.db", i, &member);
//     }
//
//     // Truncate the file by rewriting the reduced number of members
//     std::fstream file("clubsocial.db", std::ios::binary | std::ios::in | std::ios::out);
//     file.seekp((memberCount - 1) * sizeof(Member));
//     file.write("", 0);  // Truncate the file
//     file.close();
// }
//
// void ClubManager::clearAllMembers() {
//     std::ofstream file("clubsocial.db", std::ios::trunc | std::ios::binary);
//     file.close();
// }
//
// void ClubManager::addClub(const Club& club) {
//     if (clubCount < MAX_CLUBS) {
//         clubs[clubCount++] = new Club(club);
//     } else {
//         std::cerr << "Erreur : Nombre maximal de clubs atteint." << std::endl;
//     }
// }
//
// void ClubManager::removeClub(const std::string& clubName) {
//     for (int i = 0; i < clubCount; ++i) {
//         if (std::strcmp(clubs[i]->name, clubName.c_str()) == 0) {
//             delete clubs[i];
//             clubs[i] = nullptr;
//             for (int j = i; j < clubCount - 1; ++j) {
//                 clubs[j] = clubs[j + 1];
//             }
//             clubs[--clubCount] = nullptr;
//             std::cout << "Club supprimé avec succès." << std::endl;
//             return;
//         }
//     }
//     std::cerr << "Erreur : Club non trouvé." << std::endl;
// }
//
// void ClubManager::clearAllClubs() {
//     for (int i = 0; i < clubCount; ++i) {
//         delete clubs[i];
//         clubs[i] = nullptr;
//     }
//     clubCount = 0;
// }
//
