#pragma once
#include "Product.h"
#include "Seller.h"
#include <string>

// Клас Оголошення (композиція об'єктів Product та Seller)
class Advertisement {
private:
    Product product;
    Seller seller;
    std::string note; // Примітка до оголошення

public:
    Advertisement();
    Advertisement(Product product, Seller seller, std::string note = "");

    Product getProduct() const;
    Seller getSeller() const;
    std::string getNote() const;

    void setPrice(double newPrice);
    void show() const;
};
