// #include "Club.h"
// #include <iostream>
// #include <algorithm>
//
// Club::Club(int id, const std::string &name) : id(id), name(name) {}
//
// int Club::getId() const {
//     return id;
// }
//
// std::string Club::getName() const {
//     return name;
// }
//
// void Club::addMember(const Member &member) {
//     members.push_back(member);
// }
//
// void Club::removeMember(int memberId) {
//     members.erase(std::remove_if(members.begin(), members.end(), [memberId](const Member &m) { return m.getId() == memberId; }), members.end());
// }
//
// void Club::displayMembers() const {
//     for (const auto &member : members) {
//         member.display();
//     }
// }
//
// void Club::display() const {
//     std::cout << "Club ID: " << id << ", Name: " << name << std::endl;
// }
