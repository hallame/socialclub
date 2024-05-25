#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <iostream>
#include <limits>
#include "ClubManager.h"
#include "db.h"

void showMenu() {
    std::cout << "\n****************************\n";
    std::cout << "\033 CLUB SOCIAL \033\n";
    std::cout << "\033 Commandes\033\n\n ";
    std::cout << " 1. Ajouter un membre\n";
    std::cout << "2. Afficher un membre\n";
    std::cout << "3. Editer les clubs d'un membre\n";
    std::cout << "S. Statistiques\n";
    std::cout << "L. Lister les clubs\n";
    std::cout << "E. Exporter la liste des membres\n";
    std::cout << "I. Importer une liste de membres\n";
    std::cout << "D. Supprimer tous les membres\n";
    std::cout << "H. Ajouter des membres au hasard\n";
    std::cout << "Q. Quitter\n";
    std::cout << "Entrez votre choix : ";
}

void cmd_add(ClubManager& clubManager) {
    Member newMember;
    // newMember.id = db_size("clubsocial.db") + 1;
    std::cout << "Entrez le prenom du membre: ";
    std::cin.ignore();
    std::cin.getline(newMember.firstName, 41);
    std::cout << "Entrez le nom du membre: ";
    std::cin.getline(newMember.lastName, 41);
    std::cout << "Entrez la ville du membre: ";
    std::cin.getline(newMember.city, 41);
    std::cout << "Entrez l'age du membre: ";
    //std::cin >> newMember.age;
    int age;

    // Boucle tant que l'utilisateur n'entre pas un entier
    while (true) {
        std::cout << " ";
        if (!(std::cin >> newMember.age)) {
          
            std::cout << "Erreur : L'age doit etre un nombre entier." << std::endl;
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
           
            break;
        }
    }
    newMember.clubCount = 0;
    clubManager.addMember(newMember);
    db_write(db_size(), &newMember);
    //db_write(newMember.id - 1, &newMember);
    std::cout << "Membre ajoute avec succes." << std::endl;
}

void cmd_show(const ClubManager& clubManager) {
    size_t id;
    std::cout << "Entrez l'ID du membre a afficher: ";
    std::cin >> id;
    if (id < 1 || id > clubManager.getMemberCount()) {
        std::cerr << "Erreur: ID invalide." << std::endl;
        return;
    }
    Member membre = clubManager.getMember(id);
    std::cout << "Prenom: " << membre.firstName << std::endl;
    std::cout << "Nom: " << membre.lastName << std::endl;
    std::cout << "Ville: " << membre.city << std::endl;
    std::cout << "Age: " << membre.age << std::endl;
    std::cout << "Nombre de clubs: " << membre.clubCount << std::endl;
    std::cout << "Clubs: " << std::endl;
    for (int i = 0; i < membre.clubCount; ++i) {
        std::cout << "- " << membre.clubNames[i] << std::endl;
    }
}

void cmd_edit(ClubManager &clubManager) {
    int id;
    std::cout << "Entrez l'ID du membre a editer : ";
    std::cin >> id;
    std::cin.ignore();

    Member membre = clubManager.getMember(id);
    if (membre.id == -1) {
        std::cerr << "Erreur : Membre non trouve." << std::endl;
        return;
    }

    std::cout << "Edition des clubs pour " << membre.firstName << " " << membre.lastName << std::endl;
    char choix;
    do {
        std::cout << "A. Ajouter un club" << std::endl;
        std::cout << "R. Retirer un club" << std::endl;
        std::cout << "Q. Quitter l'edition" << std::endl;
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;
        std::cin.ignore();

        if (choix == 'A') {
            if (membre.clubCount < 10) {
                std::cout << "Entrez le nom du club : ";
                char clubName[41];
                std::cin.getline(clubName, 41);
                bool alreadyExists = false;
                for (int i = 0; i < membre.clubCount; ++i) {
                    if (std::strcmp(membre.clubNames[i], clubName) == 0) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists) {
                    std::strcpy(membre.clubNames[membre.clubCount++], clubName);
                    std::cout << "Club ajoute avec succes." << std::endl;
                } else {
                    std::cerr << "Erreur : Ce club est deje dans la liste." << std::endl;
                }
            } else {
                std::cerr << "Erreur : Nombre maximal de clubs atteint." << std::endl;
            }
        } else if (choix == 'R') {
            std::cout << "Entrez le nom du club a retirer : ";
            char clubName[41];
            std::cin.getline(clubName, 41);
            bool found = false;
            for (int i = 0; i < membre.clubCount; ++i) {
                if (std::strcmp(membre.clubNames[i], clubName) == 0) {
                    found = true;
                    for (int j = i; j < membre.clubCount - 1; ++j) {
                        std::strcpy(membre.clubNames[j], membre.clubNames[j + 1]);
                    }
                    --membre.clubCount;
                    std::cout << "Club retire avec succes." << std::endl;
                    break;
                }
            }
            if (!found) {
                std::cerr << "Erreur : Club non trouve." << std::endl;
            }
        }
    } while (choix != 'Q');

    clubManager.removeMember(membre.id);
    clubManager.addMember(membre);
    db_write(id - 1, &membre);
    //db_write(membre.id - 1, &membre);
}

// Fonction pour afficher les statistiques
void cmd_stats(const ClubManager &clubManager) {
    int totalClubs = 0;
    for (int i = 0; i < clubManager.getMemberCount(); ++i) {
        totalClubs += clubManager.getMembers()[i].clubCount;
    }
    float averageClubs = static_cast<float>(totalClubs) / clubManager.getMemberCount();
    std::cout << "Nombre moyen de clubs par membre : " << averageClubs << std::endl;
}

// Fonction pour lister les clubs

void cmd_list(const ClubManager &clubManager) {
    std::cout << "Liste des clubs :" << std::endl;
    for (int i = 0; i < clubManager.getClubCount(); ++i) {
        std::cout << "- " << clubManager.getClubs()[i].name << std::endl;
    }
}


// Fonction pour exporter la liste des membres
void cmd_xport(const ClubManager &clubManager) {
    std::ofstream file("membres.txt");
    if (!file) {
        std::cerr << "Erreur : Impossible de creer le fichier." << std::endl;
        return;
    }
    for (int i = 0; i < clubManager.getMemberCount(); ++i) {
        const Member &membre = clubManager.getMembers()[i];
        file << membre.id << " " << membre.firstName << " " << membre.lastName << " "
             << membre.city << " " << membre.age << " " << membre.clubCount << " ";
        for (int j = 0; j < membre.clubCount; ++j) {
            file << membre.clubNames[j] << " ";
        }
        file << std::endl;
    }
    file.close();
    std::cout << "Liste des membres exportee avec succes." << std::endl;
}

// Fonction pour importer une liste de membres
void cmd_import(ClubManager &clubManager) {
    std::ifstream file("membres.txt");
    if (!file) {
        std::cerr << "Erreur : Impossible de lire le fichier." << std::endl;
        return;
    }
    while (!file.eof()) {
        Member membre;
        file >> membre.id >> membre.firstName >> membre.lastName >> membre.city >> membre.age >> membre.clubCount;
        for (int i = 0; i < membre.clubCount; ++i) {
            file >> membre.clubNames[i];
        }
        // clubManager.addMember(membre);
        // db_write(db_size("clubsocial.db"), &membre);
        clubManager.addMember(membre);
        db_write(db_size(), &membre);
    }
    file.close();
    std::cout << "Liste des membres importee avec succes." << std::endl;
}

// Fonction pour supprimer tous les membres
void cmd_whip(ClubManager &clubManager) {
    clubManager = ClubManager();
    std::ofstream file("membres.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();
    std::cout << "Tous les membres ont ete supprimes." << std::endl;
}

// Fonction pour ajouter des membres au hasard
void cmd_rand(ClubManager &clubManager) {
    int nombre;
    std::cout << "Entrez le nombre de membres a ajouter au hasard : ";
    std::cin >> nombre;
    std::cin.ignore();
    for (int i = 0; i < nombre; ++i) {
        Member membre;
        membre.id = clubManager.getMemberCount() + 1;
        std::snprintf(membre.firstName, sizeof(membre.firstName), "Prenom%d", membre.id);
        std::snprintf(membre.lastName, sizeof(membre.lastName), "Nom%d", membre.id);
        std::snprintf(membre.city, sizeof(membre.city), "Ville%d", membre.id);
        membre.age = rand() % 100;
        membre.clubCount = rand() % 11;
        for (int j = 0; j < membre.clubCount; ++j) {
            std::snprintf(membre.clubNames[j], sizeof(membre.clubNames[j]), "Club%d", rand() % 100);
        }
        clubManager.addMember(membre);
        //db_write(db_size("clubsocial.db"), &membre);
        db_write(db_size(), &membre);

    }
    std::cout << nombre << " membres sont ajoutes au hasard." << std::endl;
}

// Fonction principale
int main() {
    ClubManager clubManager;
    const std::string dbFile = "clubsocial.db";
    std::ifstream file(dbFile, std::ios::binary);
    if (file) {
        file.close();
    } else {
        std::ofstream createFile(dbFile, std::ios::binary);
        createFile.close();
    }

    char choix;
    do {
        showMenu();
        std::cin >> choix;
        std::cin.ignore();
        switch (choix) {
            case '1':
                cmd_add(clubManager);
            break;
            case '2':
                cmd_show(clubManager);
            break;
            case '3':
                cmd_edit(clubManager);
            break;
            case 'S':
                cmd_stats(clubManager);
                break;
            case 'L':
                cmd_list(clubManager);
                break;
            case 'E':
                cmd_xport(clubManager);
                break;
            case 'I':
                cmd_import(clubManager);
                break;
            case 'D':
                cmd_whip(clubManager);
                break;
            case 'H':
                cmd_rand(clubManager);
                break;
            case 'Q':
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cerr << "Choix invalide. Veuillez reessayer." << std::endl;
                break;
        }
    } while (choix != 'Q');

    return 0;
}
