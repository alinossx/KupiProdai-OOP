#include "User.h"

User::User(int id, std::string name, std::string contact)
    : id(id), name(name), contact(contact) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getContact() const { return contact; }
