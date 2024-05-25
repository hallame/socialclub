#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H

#include "Member.h"
#include "Club.h"
#include <string>


class ClubManager {
public:
    ClubManager();
    ~ClubManager();
    void addMember(const Member& member);
    void removeMember(int memberId);
    void addClub(const Club& club);
    void removeClub(const std::string& clubName);
    void clearAllMembers();
    void clearAllClubs();
    void displayMembers() const;
    Member getMember(int id) const;
    int getMemberCount() const { return memberCount; }

    const Member* getMembers() const { return members; }
    const Club* getClubs() const { return clubs; }
    int getClubCount() const { return clubCount; }

private:
    static const int MAX_MEMBERS = 100;
    static const int MAX_CLUBS = 50;
    Member members[MAX_MEMBERS];
    Club clubs[MAX_CLUBS];
    int memberCount;
    int clubCount;

};




// class ClubManager {
// public:
//     ClubManager();
//     ~ClubManager();
//
//     void addMember(const Member& member);
//     void removeMember(size_t index);
//     Member getMember(size_t index) const;
//     size_t getMemberCount() const;
//     void displayMembers() const;
//     void clearAllMembers();
//
//     void addClub(const Club& club);
//     void removeClub(const std::string& clubName);
//     void clearAllClubs();
//     size_t getClubCount() const;
//     Club* getClubs() const;
//
// private:
//     static const int MAX_CLUBS = 50;
//     Club* clubs[MAX_CLUBS];
//     int clubCount;
// };

#endif // CLUBMANAGER_H
