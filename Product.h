#pragma once
#include <string>

// Клас Товар
class Product {
private:
    int id;
    std::string title;
    std::string category;
    int quantity;
    double price;

public:
    Product(int id = 0, std::string title = "", std::string category = "", int quantity = 1, double price = 0.0);

    int getId() const;
    std::string getTitle() const;
    std::string getCategory() const;
    int getQuantity() const;
    double getPrice() const;

    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
};
