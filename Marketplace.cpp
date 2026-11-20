#include "Marketplace.h"
#include "FileManager.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>

Marketplace::Marketplace() {
    FileManager::load(ads); // Автоматичне завантаження бази при запуску
}

int Marketplace::getSafeInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "[Помилка] Введіть коректне ціле невід'ємне число!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double Marketplace::getSafeDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0.0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "[Помилка] Введіть коректне числове значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Marketplace::addAdvertisement() {
    std::cout << "\n=== ДОДАВАННЯ НОВОГО ОГОЛОШЕННЯ ===\n";
    int id = getSafeInt("Введіть унікальний ID оголошення: ");

    for (const auto& a : ads) {
        if (a.getProduct().getId() == id) {
            std::cout << "[Помилка] Оголошення з таким ID вже існує!\n";
            return;
        }
    }

    std::string title, category, sellerName, contact, terms, note;
    std::cout << "Найменування товару: ";
    std::getline(std::cin, title);

    std::cout << "Категорія товару: ";
    std::getline(std::cin, category);

    int qty = getSafeInt("Кількість одиниць (обсяг партії): ");
    double price = getSafeDouble("Ціна (грн): ");

    std::cout << "Ім'я продавця: ";
    std::getline(std::cin, sellerName);

    std::cout << "Контактний телефон або адреса: ";
    std::getline(std::cin, contact);

    std::cout << "Умови продажу / доставки: ";
    std::getline(std::cin, terms);

    std::cout << "Примітка (необов'язково): ";
    std::getline(std::cin, note);

    Product p(id, title, category, qty, price);
    Seller s(id + 1000, sellerName, contact, terms);
    ads.emplace_back(p, s, note);

    std::cout << "\n[Успіх] Оголошення успішно додано до системи!\n";
}

void Marketplace::showAll() const {
    if (ads.empty()) {
        std::cout << "\n[Інформація] Список оголошень порожній.\n";
        return;
    }
    std::cout << "\n=== УСІ АКТУАЛЬНІ ОГОЛОШЕННЯ (" << ads.size() << ") ===\n";
    for (const auto& a : ads) {
        a.show();
    }
}

void Marketplace::searchByTitle() const {
    std::string query;
    std::cout << "\nВведіть назву або частину назви товару для пошуку: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& a : ads) {
        if (a.getProduct().getTitle().find(query) != std::string::npos) {
            a.show();
            found = true;
        }
    }
    if (!found) {
        std::cout << "[Інформація] За запитом \"" << query << "\" нічого не знайдено.\n";
    }
}

void Marketplace::searchByCategory() const {
    std::string cat;
    std::cout << "\nВведіть категорію для фільтрації: ";
    std::getline(std::cin, cat);

    bool found = false;
    for (const auto& a : ads) {
        if (a.getProduct().getCategory() == cat) {
            a.show();
            found = true;
        }
    }
    if (!found) {
        std::cout << "[Інформація] У категорії \"" << cat << "\" оголошень не знайдено.\n";
    }
}

void Marketplace::matchForBuyer() {
    std::cout << "\n=== ПІДБІР ПРОПОЗИЦІЙ ДЛЯ ПОКУПЦЯ ===\n";
    std::string buyerName, contact, desiredTitle;
    std::cout << "Ваше ім'я: ";
    std::getline(std::cin, buyerName);
    std::cout << "Ваш контактний телефон: ";
    std::getline(std::cin, contact);
    double budget = getSafeDouble("Максимальний прийнятний бюджет (грн): ");

    Buyer buyer(1, buyerName, contact, budget);

    std::cout << "Який товар шукаєте (або натисніть Enter для всіх): ";
    std::getline(std::cin, desiredTitle);

    std::cout << "\nРезультати підбору для користувача [" << buyer.getRole() << ": " << buyer.getName() << "]:\n";
    bool found = false;
    for (const auto& a : ads) {
        bool priceOk = a.getProduct().getPrice() <= buyer.getMaxBudget();
        bool titleOk = desiredTitle.empty() || (a.getProduct().getTitle().find(desiredTitle) != std::string::npos);
        if (priceOk && titleOk) {
            a.show();
            found = true;
        }
    }
    if (!found) {
        std::cout << "[Інформація] Підходящих пропозицій у межах бюджету " << budget << " грн не знайдено.\n";
    }
}

void Marketplace::editPrice() {
    int id = getSafeInt("\nВведіть ID оголошення для зміни ціни: ");
    for (auto& a : ads) {
        if (a.getProduct().getId() == id) {
            std::cout << "Поточна ціна: " << a.getProduct().getPrice() << " грн\n";
            double newPrice = getSafeDouble("Введіть нову ціну (грн): ");
            a.setPrice(newPrice);
            std::cout << "[Успіх] Ціну успішно оновлено!\n";
            return;
        }
    }
    std::cout << "[Помилка] Оголошення з ID " << id << " не знайдено.\n";
}

void Marketplace::sortByPrice() {
    if (ads.empty()) {
        std::cout << "\n[Інформація] Немає даних для сортування.\n";
        return;
    }
    std::sort(ads.begin(), ads.end(), [](const Advertisement& a, const Advertisement& b) {
        return a.getProduct().getPrice() < b.getProduct().getPrice();
    });
    std::cout << "\n[Успіх] Оголошення відсортовано за зростанням ціни.\n";
    showAll();
}

void Marketplace::removeAdvertisement() {
    int id = getSafeInt("\nВведіть ID оголошення для видалення: ");
    auto it = std::find_if(ads.begin(), ads.end(), [id](const Advertisement& a) {
        return a.getProduct().getId() == id;
    });

    if (it == ads.end()) {
        std::cout << "[Помилка] Оголошення з ID " << id << " не знайдено.\n";
        return;
    }

    std::cout << "Ви впевнені, що бажаєте видалити товар \"" << it->getProduct().getTitle() << "\"? (1 - Так, 0 - Ні): ";
    int confirm = getSafeInt("");
    if (confirm == 1) {
        ads.erase(it);
        std::cout << "[Успіх] Оголошення видалено з бази.\n";
    } else {
        std::cout << "[Скасовано] Видалення відмінено користувачем.\n";
    }
}

void Marketplace::saveToFile() const {
    if (FileManager::save(ads)) {
        std::cout << "\n[Успіх] Усі дані збережено у файл ads.txt.\n";
    } else {
        std::cout << "\n[Помилка] Не вдалося відкрити файл для запису.\n";
    }
}

void Marketplace::loadFromFile() {
    if (FileManager::load(ads)) {
        std::cout << "\n[Успіх] Завантажено оголошень: " << ads.size() << ".\n";
    } else {
        std::cout << "\n[Помилка] Файл ads.txt не знайдено або пошкоджено.\n";
    }
}

void Marketplace::showStatistics() const {
    std::cout << "\n=== СТАТИСТИКА СИСТЕМИ «КУПИ-ПРОДАЙ» ===\n";
    std::cout << "Загальна кількість активних оголошень : " << ads.size() << "\n";
    double totalSum = 0.0;
    int totalItems = 0;
    for (const auto& a : ads) {
        totalSum += a.getProduct().getPrice() * a.getProduct().getQuantity();
        totalItems += a.getProduct().getQuantity();
    }
    std::cout << "Загальна кількість одиниць товарів    : " << totalItems << " шт.\n";
    std::cout << "Сумарна вартість усіх пропозицій      : " << std::fixed << std::setprecision(2) << totalSum << " грн\n";
}
