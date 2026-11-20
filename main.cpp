#include <iostream>
#include <limits>
#include "Marketplace.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    Marketplace system;
    int choice = -1;

    do {
        std::cout << "\n==================================================\n"
                  << "      ІНФОРМАЦІЙНА СИСТЕМА «КУПИ-ПРОДАЙ»\n"
                  << "==================================================\n"
                  << " 1. Додати нове оголошення\n"
                  << " 2. Переглянути всі оголошення\n"
                  << " 3. Пошук товару за назвою\n"
                  << " 4. Фільтрація оголошень за категорією\n"
                  << " 5. Підбір пропозицій для покупця (за бюджетом)\n"
                  << " 6. Редагувати ціну оголошення\n"
                  << " 7. Сортувати оголошення за зростанням ціни\n"
                  << " 8. Видалити оголошення\n"
                  << " 9. Зберегти дані у файл\n"
                  << "10. Завантажити дані з файлу\n"
                  << "11. Статистика системи\n"
                  << " 0. Вихід із програми\n"
                  << "--------------------------------------------------\n"
                  << "Оберіть пункт меню: ";

        if (!(std::cin >> choice)) {
            std::cout << "\n[Помилка] Некоректне введення! Введіть цифру від 0 до 11.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:  system.addAdvertisement(); break;
            case 2:  system.showAll(); break;
            case 3:  system.searchByTitle(); break;
            case 4:  system.searchByCategory(); break;
            case 5:  system.matchForBuyer(); break;
            case 6:  system.editPrice(); break;
            case 7:  system.sortByPrice(); break;
            case 8:  system.removeAdvertisement(); break;
            case 9:  system.saveToFile(); break;
            case 10: system.loadFromFile(); break;
            case 11: system.showStatistics(); break;
            case 0:
                system.saveToFile();
                std::cout << "\nРоботу завершено. Дякуємо за використання системи!\n";
                break;
            default:
                std::cout << "\n[Помилка] Невідомий пункт меню. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
