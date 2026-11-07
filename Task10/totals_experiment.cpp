#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>
#include <string>

constexpr long long AVERAGE_FARE_PAISE = 1785; // Rs 17.85, derived below

int main() {
    const long long journeyCounts[] = {20000LL, 500000LL, 3000000LL};

    // Distribution: 50% Inner, 30% Middle, 20% Outer.
    // Base weighted average = 0.5*1000 + 0.3*2000 + 0.2*3000 = 1700 paise.
    // With 25% of journeys receiving a 20% peak surcharge evenly by zone:
    // average = 1700 * (1 + 0.25*0.20) = 1785 paise.
    const long long expectedFarePaise = AVERAGE_FARE_PAISE;
    const double expectedFareRupees = 17.85;

    std::cout << "AVERAGE FARE MODEL: Rs 17.85 per journey\n";
    std::cout << "int max = " << INT_MAX << '\n';
    std::cout << "sizeof(int) = " << sizeof(int)
              << ", sizeof(long long) = " << sizeof(long long)
              << ", sizeof(double) = " << sizeof(double) << " bytes\n\n";

    for (long long n : journeyCounts) {
        long long integerTotalPaise = 0;
        double doubleTotalRupees = 0.0;

        for (long long i = 0; i < n; ++i) {
            integerTotalPaise += expectedFarePaise;
            doubleTotalRupees += expectedFareRupees;
        }

        const long long exactExpectedPaise = n * expectedFarePaise;
        const double doubleAsPaise = doubleTotalRupees * 100.0;

        std::cout << "Journeys: " << n << '\n';
        std::cout << "Integer total: " << integerTotalPaise
                  << " paise = Rs " << std::fixed << std::setprecision(2)
                  << integerTotalPaise / 100.0 << '\n';
        std::cout << "Double total:  Rs " << std::setprecision(10)
                  << doubleTotalRupees << '\n';
        std::cout << "Integer arithmetic matches formula: "
                  << (integerTotalPaise == exactExpectedPaise ? "YES" : "NO") << '\n';
        std::cout << "Double minus integer (paise): "
                  << std::setprecision(12)
                  << (doubleAsPaise - static_cast<double>(integerTotalPaise))
                  << "\n\n";
    }

    const long long networkTotalPaise = 3000000LL * expectedFarePaise;
    std::cout << "Network total in paise: " << networkTotalPaise << '\n';
    std::cout << "Exceeds signed int max: "
              << (networkTotalPaise > INT_MAX ? "YES" : "NO") << '\n';

    // Demonstrate the mathematical threshold; do not execute signed int overflow,
    // because signed overflow in C++ is undefined behaviour.
    std::cout << "A signed 32-bit int cannot safely hold this network total.\n";
    std::cout << "long long max: " << std::numeric_limits<long long>::max() << '\n';
    return 0;
}
