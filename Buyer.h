#pragma once
#include "User.h"

// Похідний клас Покупця
class Buyer : public User {
private:
    double maxBudget; // Максимальний прийнятний бюджет

public:
    Buyer(int id = 0, std::string name = "", std::string contact = "", double maxBudget = 0.0);
    std::string getRole() const override;
    double getMaxBudget() const;
};
