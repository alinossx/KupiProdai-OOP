#include "Product.h"

Product::Product(int id, std::string title, std::string category, int quantity, double price)
    : id(id), title(title), category(category), quantity(quantity), price(price) {}

int Product::getId() const { return id; }
std::string Product::getTitle() const { return title; }
std::string Product::getCategory() const { return category; }
int Product::getQuantity() const { return quantity; }
double Product::getPrice() const { return price; }

void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
