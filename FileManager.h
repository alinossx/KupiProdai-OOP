#pragma once
#include <vector>
#include <string>
#include "Advertisement.h"

// Клас для керування збереженням та завантаженням даних із текстового файлу
class FileManager {
public:
    static bool save(const std::vector<Advertisement>& ads, const std::string& filename = "ads.txt");
    static bool load(std::vector<Advertisement>& ads, const std::string& filename = "ads.txt");
};
