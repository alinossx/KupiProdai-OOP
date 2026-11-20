#include "Seller.h"

Seller::Seller(int id, std::string name, std::string contact, std::string deliveryTerms)
    : User(id, name, contact), deliveryTerms(deliveryTerms) {}

std::string Seller::getRole() const { return "Продавець"; }
std::string Seller::getDeliveryTerms() const { return deliveryTerms; }
