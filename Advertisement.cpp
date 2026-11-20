#include "Advertisement.h"
#include <iostream>
#include <iomanip>

Advertisement::Advertisement() {}

Advertisement::Advertisement(Product product, Seller seller, std::string note)
    : product(product), seller(seller), note(note) {}

Product Advertisement::getProduct() const { return product; }
Seller Advertisement::getSeller() const { return seller; }
std::string Advertisement::getNote() const { return note; }

void Advertisement::setPrice(double newPrice) {
    product.setPrice(newPrice);
}

void Advertisement::show() const {
    std::cout << "--------------------------------------------------\n"
              << "ID оголошення : " << product.getId() << "\n"
              << "Товар         : " << product.getTitle() << " (Категорія: " << product.getCategory() << ")\n"
              << "Кількість     : " << product.getQuantity() << " шт.\n"
              << "Ціна          : " << std::fixed << std::setprecision(2) << product.getPrice() << " грн\n"
              << "Автор (" << seller.getRole() << "): " << seller.getName() << "\n"
              << "Контакти      : " << seller.getContact() << "\n"
              << "Умови         : " << seller.getDeliveryTerms() << "\n"
              << "Примітка      : " << (note.empty() ? "відсутня" : note) << "\n";
}
