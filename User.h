#pragma once
#include <string>

// Базовий абстрактний клас користувача системи
class User {
protected:
    int id;
    std::string name;
    std::string contact;

public:
    User(int id = 0, std::string name = "", std::string contact = "");
    virtual ~User() {}

    // Віртуальний метод для реалізації поліморфізму
    virtual std::string getRole() const = 0;

    int getId() const;
    std::string getName() const;
    std::string getContact() const;
};
