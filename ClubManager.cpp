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
