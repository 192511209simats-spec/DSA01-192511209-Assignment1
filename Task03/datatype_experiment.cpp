#include <climits>
#include <iomanip>
#include <iostream>
#include <string>

enum class Zone : int {
    Inner,
    Middle,
    Outer
};

int main() {
    std::cout << "TYPE SIZES (bytes)\n";
    std::cout << "bool: " << sizeof(bool) << '\n';
    std::cout << "char: " << sizeof(char) << '\n';
    std::cout << "int: " << sizeof(int) << '\n';
    std::cout << "unsigned int: " << sizeof(unsigned int) << '\n';
    std::cout << "long long: " << sizeof(long long) << '\n';
    std::cout << "float: " << sizeof(float) << '\n';
    std::cout << "double: " << sizeof(double) << '\n';
    std::cout << "Zone: " << sizeof(Zone) << "\n\n";

    std::cout << "INTEGER LIMITS\n";
    std::cout << "CHAR_MIN: " << static_cast<int>(CHAR_MIN) << '\n';
    std::cout << "CHAR_MAX: " << static_cast<int>(CHAR_MAX) << '\n';
    std::cout << "INT_MIN: " << INT_MIN << '\n';
    std::cout << "INT_MAX: " << INT_MAX << '\n';
    std::cout << "UINT_MAX: " << UINT_MAX << '\n';
    std::cout << "LLONG_MIN: " << LLONG_MIN << '\n';
    std::cout << "LLONG_MAX: " << LLONG_MAX << "\n\n";

    constexpr long long maxIllustratedFarePaise = 3600;
    constexpr long long networkJourneys = 3000000;
    constexpr long long networkTotalPaise =
        maxIllustratedFarePaise * networkJourneys;

    std::cout << "NETWORK TOTAL CHECK\n";
    std::cout << "Illustrative maximum fare (paise): "
              << maxIllustratedFarePaise << '\n';
    std::cout << "Journeys per day: " << networkJourneys << '\n';
    std::cout << "Total (paise): " << networkTotalPaise << '\n';
    std::cout << "INT_MAX: " << INT_MAX << '\n';
    std::cout << "Fits in int (paise): "
              << std::boolalpha
              << (networkTotalPaise <= INT_MAX) << "\n\n";

    std::cout << "FLOATING-POINT ACCUMULATION EXPERIMENT\n";
    const long long journeyCounts[] = {20000, 500000, 3000000};

    for (long long n : journeyCounts) {
        double doubleTotal = 0.0;
        long long integerPaiseTotal = 0;

        for (long long i = 0; i < n; ++i) {
            doubleTotal += 0.10;
            integerPaiseTotal += 10;
        }

        const long double integerReference =
            static_cast<long double>(integerPaiseTotal) / 100.0L;
        const long double error =
            static_cast<long double>(doubleTotal) - integerReference;

        std::cout << "Journeys: " << n
                  << " | double total: " << std::setprecision(17)
                  << doubleTotal
                  << " | integer-paise total (Rs): "
                  << static_cast<long double>(integerPaiseTotal) / 100.0L
                  << " | difference (Rs): " << std::scientific
                  << error << std::defaultfloat << '\n';
    }

    return 0;
}
