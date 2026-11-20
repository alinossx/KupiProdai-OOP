#include "Buyer.h"

Buyer::Buyer(int id, std::string name, std::string contact, double maxBudget)
    : User(id, name, contact), maxBudget(maxBudget) {}

std::string Buyer::getRole() const { return "Покупець"; }
double Buyer::getMaxBudget() const { return maxBudget; }
