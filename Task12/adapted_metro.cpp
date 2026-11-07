#include <iostream>
#include <iomanip>
#include <array>
#include <string>

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };

constexpr std::array<long long, 4> BASE_PAISE = {
    1000, 2000, 3000, 6000
};
constexpr long long PEAK_PERCENT = 20;
constexpr long long WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

std::string zoneName(Zone zone) {
    switch (zone) {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
    }
    return "Unknown";
}

long long calculateFare(Zone zone, bool peak, bool weekend) {
    const std::size_t index = static_cast<std::size_t>(zone);
    if (index >= BASE_PAISE.size()) return -1;

    const long long base = BASE_PAISE[index];

    // Weekend discount takes precedence; it never combines with peak surcharge.
    if (weekend) {
        return (base * (100 - WEEKEND_DISCOUNT_PERCENT) + 50) / 100;
    }
    if (peak) {
        return base + (base * PEAK_PERCENT / 100);
    }
    return base;
}

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long initialBalance)
        : balancePaise(initialBalance >= 0 ? initialBalance : 0) {}

    long long balance() const { return balancePaise; }

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise >= farePaise &&
               balancePaise - farePaise >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
};

class MonthlyPass {
private:
    std::array<Zone, 2> coveredZones;
    bool active;

public:
    MonthlyPass(Zone first, Zone second, bool isActive)
        : coveredZones{first, second}, active(isActive) {}

    bool covers(Zone zone) const {
        return active &&
               (zone == coveredZones[0] || zone == coveredZones[1]);
    }
};

void printMoney(long long paise) {
    std::cout << "Rs " << paise / 100 << '.'
              << std::setw(2) << std::setfill('0') << paise % 100
              << std::setfill(' ');
}

void processJourney(SmartCard& card, const MonthlyPass& pass,
                    Zone zone, bool peak, bool weekend) {
    const bool passUsed = pass.covers(zone);
    const long long fare = passUsed ? 0 : calculateFare(zone, peak, weekend);

    std::cout << zoneName(zone) << " journey: ";
    if (fare < 0) {
        std::cout << "invalid zone\n";
        return;
    }

    if (!card.deduct(fare)) {
        std::cout << "DENIED (minimum balance rule), balance ";
        printMoney(card.balance());
        std::cout << '\n';
        return;
    }

    std::cout << (passUsed ? "monthly pass" : "fare ");
    if (!passUsed) printMoney(fare);
    std::cout << " accepted; remaining balance ";
    printMoney(card.balance());
    std::cout << '\n';
}

int main() {
    SmartCard card(20000); // Rs 200.00
    MonthlyPass pass(Zone::Inner, Zone::Middle, true);

    std::cout << "REVISED METRO FARE DEMONSTRATION\n";
    processJourney(card, pass, Zone::Inner, true, false);     // Pass covers zone
    processJourney(card, pass, Zone::Airport, true, false);   // Airport peak = Rs 72
    processJourney(card, pass, Zone::Outer, true, true);      // Weekend replaces peak = Rs 27
    processJourney(card, pass, Zone::Outer, false, false);    // Outer off-peak = Rs 30

    std::cout << "\nWorked fare examples:\n";
    std::cout << "Airport peak (no weekend): ";
    printMoney(calculateFare(Zone::Airport, true, false));
    std::cout << "\nAirport weekend (even if peak flag is true): ";
    printMoney(calculateFare(Zone::Airport, true, true));
    std::cout << "\n";
    return 0;
}
