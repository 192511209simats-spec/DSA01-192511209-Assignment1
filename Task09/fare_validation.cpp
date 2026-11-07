#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

enum class Zone { Inner, Middle, Outer, Unknown };

constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr long long PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakHour(int hour) {
    if (hour < 0 || hour > 23) return false;
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

bool parseHour(const std::string& input, int& hour) {
    std::istringstream stream(input);
    char extra = '\0';
    if (!(stream >> hour)) return false;
    if (stream >> extra) return false;
    return hour >= 0 && hour <= 23;
}

bool parseZone(int value, Zone& zone) {
    switch (value) {
        case 1: zone = Zone::Inner; return true;
        case 2: zone = Zone::Middle; return true;
        case 3: zone = Zone::Outer; return true;
        default: zone = Zone::Unknown; return false;
    }
}

long long calculateFare(Zone zone, bool peak) {
    long long base = 0;
    switch (zone) {
        case Zone::Inner:  base = BASE_PAISE[0]; break;
        case Zone::Middle: base = BASE_PAISE[1]; break;
        case Zone::Outer:  base = BASE_PAISE[2]; break;
        default: return -1;
    }
    return peak ? base + (base * PEAK_PERCENT / 100) : base;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE_PAISE;
}

bool recharge(long long& balance, long long amountPaise) {
    if (amountPaise < 0) return false;
    balance += amountPaise;
    return true;
}

std::string money(long long paise) {
    std::ostringstream out;
    out << "Rs " << paise / 100 << '.'
        << std::setw(2) << std::setfill('0') << paise % 100;
    return out.str();
}

struct TestCase {
    std::string name;
    Zone zone;
    int hour;
    long long balance;
    long long expectedFare;
    bool expectedAllowed;
};

int main() {
    const std::vector<TestCase> tests = {
        {"Inner off-peak", Zone::Inner, 11, 10000, 1000, true},
        {"Middle off-peak", Zone::Middle, 12, 10000, 2000, true},
        {"Outer off-peak", Zone::Outer, 13, 10000, 3000, true},
        {"Inner peak", Zone::Inner, 8, 10000, 1200, true},
        {"Middle peak", Zone::Middle, 9, 10000, 2400, true},
        {"Outer peak", Zone::Outer, 18, 10000, 3600, true},
        {"Boundary 08:00 is peak", Zone::Inner, 8, 10000, 1200, true},
        {"Boundary 10:00 is off-peak", Zone::Inner, 10, 10000, 1000, true},
        {"Boundary 17:00 is peak", Zone::Inner, 17, 10000, 1200, true},
        {"Boundary 20:00 is off-peak", Zone::Inner, 20, 10000, 1000, true},
        {"Leaves exactly Rs 50", Zone::Outer, 11, 8000, 3000, true},
        {"Would leave less than Rs 50", Zone::Outer, 11, 7999, 3000, false},
        {"Unknown zone rejected", Zone::Unknown, 11, 10000, -1, false}
    };

    int passed = 0;
    std::cout << "FARE VALIDATION TESTS\n";
    std::cout << std::left << std::setw(34) << "Test"
              << std::setw(16) << "Expected fare"
              << std::setw(16) << "Actual fare"
              << "Expected/Actual access\n";

    for (const TestCase& test : tests) {
        const bool peak = isPeakHour(test.hour);
        const long long actualFare = calculateFare(test.zone, peak);
        const bool actualAllowed = canTravel(test.balance, actualFare);
        const bool ok = actualFare == test.expectedFare &&
                        actualAllowed == test.expectedAllowed;
        if (ok) ++passed;

        std::cout << std::left << std::setw(34) << test.name
                  << std::setw(16)
                  << (test.expectedFare < 0 ? "INVALID" : money(test.expectedFare))
                  << std::setw(16)
                  << (actualFare < 0 ? "INVALID" : money(actualFare))
                  << (test.expectedAllowed ? "ALLOW" : "DENY") << "/"
                  << (actualAllowed ? "ALLOW" : "DENY")
                  << "  " << (ok ? "PASS" : "FAIL") << '\n';
    }

    std::cout << "\nPassed: " << passed << "/" << tests.size() << '\n';

    long long balance = 10000;
    const long long beforeInvalidRecharge = balance;
    const bool negativeRechargeAccepted = recharge(balance, -500);
    std::cout << "Negative recharge rejected: "
              << (!negativeRechargeAccepted && balance == beforeInvalidRecharge
                  ? "PASS" : "FAIL") << '\n';

    int hour = 0;
    const bool lettersAccepted = parseHour("nine", hour);
    std::cout << "Letters rejected as hour: "
              << (!lettersAccepted ? "PASS" : "FAIL") << '\n';

    // Five journeys, calculated manually:
    // Inner off-peak 1000 + Middle peak 2400 + Outer off-peak 3000
    // + Inner peak 1200 + Middle off-peak 2000 = 9600 paise.
    const long long fiveJourneyTotal =
        calculateFare(Zone::Inner, false) +
        calculateFare(Zone::Middle, true) +
        calculateFare(Zone::Outer, false) +
        calculateFare(Zone::Inner, true) +
        calculateFare(Zone::Middle, false);

    std::cout << "Five-journey total: " << money(fiveJourneyTotal)
              << " (expected Rs 96.00) "
              << (fiveJourneyTotal == 9600 ? "PASS" : "FAIL") << '\n';

    return passed == static_cast<int>(tests.size()) &&
           !negativeRechargeAccepted && !lettersAccepted &&
           fiveJourneyTotal == 9600 ? 0 : 1;
}
