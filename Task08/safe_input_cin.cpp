#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

bool readInteger(const std::string& prompt, int& value)
{
    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
            return true;

        if (std::cin.eof())
            return false;

        std::cout << "Invalid input. Please enter a whole number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool readZone(int& zone)
{
    while (true)
    {
        if (!readInteger("Enter zone (1=Inner, 2=Middle, 3=Outer): ", zone))
            return false;

        if (zone >= 1 && zone <= 3)
            return true;

        std::cout << "Unknown zone. Choose 1, 2 or 3.\n";
    }
}

int main()
{
    int hour = 0;
    int zone = 0;

    if (!readInteger("Enter hour (0-23): ", hour))
        return 0;

    while (hour < 0 || hour > 23)
    {
        std::cout << "Hour must be between 0 and 23.\n";
        if (!readInteger("Enter hour (0-23): ", hour))
            return 0;
    }

    if (!readZone(zone))
        return 0;

    const bool peak = (hour >= 8 && hour < 10) ||
                      (hour >= 17 && hour < 20);

    const long long basePaise[] = {0, 1000, 2000, 3000};
    long long farePaise = basePaise[zone];

    if (peak)
        farePaise += farePaise * 20 / 100;

    std::cout << "\n========== JOURNEY REPORT ==========\n";
    std::cout << std::left << std::setw(18) << "Zone"
              << ": " << (zone == 1 ? "Inner" :
                           zone == 2 ? "Middle" : "Outer") << '\n';
    std::cout << std::left << std::setw(18) << "Entry hour"
              << ": " << hour << ":00\n";
    std::cout << std::left << std::setw(18) << "Period"
              << ": " << (peak ? "Peak" : "Off-peak") << '\n';
    std::cout << std::left << std::setw(18) << "Fare"
              << ": Rs " << std::fixed << std::setprecision(2)
              << farePaise / 100.0 << '\n';
    std::cout << "====================================\n";
}
