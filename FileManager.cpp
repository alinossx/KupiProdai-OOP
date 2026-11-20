#include "FileManager.h"
#include <fstream>
#include <sstream>

bool FileManager::save(const std::vector<Advertisement>& ads, const std::string& filename) {
    std::ofstream f(filename);
    if (!f.is_open()) return false;

    for (const auto& a : ads) {
        Product p = a.getProduct();
        Seller s = a.getSeller();
        f << p.getId() << ";"
          << p.getTitle() << ";"
          << p.getCategory() << ";"
          << p.getQuantity() << ";"
          << p.getPrice() << ";"
          << s.getId() << ";"
          << s.getName() << ";"
          << s.getContact() << ";"
          << s.getDeliveryTerms() << ";"
          << a.getNote() << "\n";
    }
    return true;
}

bool FileManager::load(std::vector<Advertisement>& ads, const std::string& filename) {
    std::ifstream f(filename);
    if (!f.is_open()) return false;

    ads.clear();
    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string fields[10];
        for (int i = 0; i < 10; ++i) {
            std::getline(ss, fields[i], ';');
        }

        try {
            int prodId = std::stoi(fields[0]);
            std::string title = fields[1];
            std::string category = fields[2];
            int qty = std::stoi(fields[3]);
            double price = std::stod(fields[4]);
            int sellerId = std::stoi(fields[5]);
            std::string sellerName = fields[6];
            std::string contact = fields[7];
            std::string terms = fields[8];
            std::string note = fields[9];

            Product p(prodId, title, category, qty, price);
            Seller s(sellerId, sellerName, contact, terms);
            ads.emplace_back(p, s, note);
        } catch (...) {
            continue; // Пропуск пошкодженого рядка
        }
    }
    return true;
}
