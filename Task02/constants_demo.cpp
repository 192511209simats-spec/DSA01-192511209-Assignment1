#include <iostream>

// Scoped enumeration for the three metro zones.
enum class Zone {
    Inner,
    Middle,
    Outer
};

// Fare values are represented in paise.
constexpr long long BASE_PAISE[] = {
    1000, // Rs 10
    2000, // Rs 20
    3000  // Rs 30
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    const Zone selectedZone = Zone::Outer;

    std::cout << "Inner fare (paise): " << BASE_PAISE[0] << '\n';
    std::cout << "Middle fare (paise): " << BASE_PAISE[1] << '\n';
    std::cout << "Outer fare (paise): " << BASE_PAISE[2] << '\n';
    std::cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    std::cout << "Minimum remaining balance (paise): "
              << MIN_BALANCE_PAISE << '\n';

    if (selectedZone == Zone::Outer) {
        std::cout << "Selected zone: Outer\n";
    }

    return 0;
}
