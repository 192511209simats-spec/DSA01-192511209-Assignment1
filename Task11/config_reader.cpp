#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream file("fare_config.txt");
    if (!file) {
        std::cerr << "Unable to open fare_config.txt\n";
        return 1;
    }

    std::map<std::string, long long> values;
    std::string key;
    long long value = 0;

    while (file >> key >> value) {
        if (value < 0) {
            std::cerr << "Invalid negative value for " << key << '\n';
            return 1;
        }
        values[key] = value;
    }

    const char* required[] = {
        "INNER", "MIDDLE", "OUTER", "PEAK_PERCENT", "MIN_BALANCE_PAISE"
    };
    for (const char* item : required) {
        if (values.find(item) == values.end()) {
            std::cerr << "Missing configuration key: " << item << '\n';
            return 1;
        }
    }

    std::cout << "Fare configuration loaded successfully\n";
    std::cout << "Inner: Rs " << values["INNER"] / 100.0 << '\n';
    std::cout << "Middle: Rs " << values["MIDDLE"] / 100.0 << '\n';
    std::cout << "Outer: Rs " << values["OUTER"] / 100.0 << '\n';
    std::cout << "Peak surcharge: " << values["PEAK_PERCENT"] << "%\n";
    std::cout << "Minimum remaining balance: Rs "
              << values["MIN_BALANCE_PAISE"] / 100.0 << '\n';
    return 0;
}
