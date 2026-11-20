#pragma once
#include <vector>
#include "Advertisement.h"
#include "Buyer.h"

// Головний керуючий клас інформаційної системи «Купи-продай»
class Marketplace {
private:
    std::vector<Advertisement> ads;
    int getSafeInt(const std::string& prompt);
    double getSafeDouble(const std::string& prompt);

public:
    Marketplace();
    void addAdvertisement();
    void showAll() const;
    void searchByTitle() const;
    void searchByCategory() const;
    void matchForBuyer();
    void editPrice();
    void sortByPrice();
    void removeAdvertisement();
    void saveToFile() const;
    void loadFromFile();
    void showStatistics() const;
};
