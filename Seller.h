#pragma once
#include "User.h"

// Похідний клас Продавця
class Seller : public User {
private:
    std::string deliveryTerms; // Умови відвантаження / доставки

public:
    Seller(int id = 0, std::string name = "", std::string contact = "", std::string deliveryTerms = "");
    std::string getRole() const override;
    std::string getDeliveryTerms() const;
};
