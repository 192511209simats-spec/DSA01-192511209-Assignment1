#include <iomanip>
#include <iostream>
#include <string>

bool readIntegerLine(const std::string& prompt, int& value)
{
    while (true)
    {
        std::string line;
        std::cout << prompt;

        if (!std::getline(std::cin, line))
            return false;

        try
        {
            std::size_t used = 0;
            int parsed = std::stoi(line, &used);

            // Reject trailing non-whitespace characters.
            while (used < line.size() &&
                   (line[used] == ' ' || line[used] == '\t' ||
                    line[used] == '\r'))
                ++used;

            if (used != line.size())
                throw std::invalid_argument("extra characters");

            value = parsed;
            return true;
        }
        catch (const std::exception&)
        {
            std::cout << "Invalid whole number. Try again.\n";
        }
    }
}

int main()
{
    int hour = 0;
    int zone = 0;

    if (!readIntegerLine("Enter hour (0-23): ", hour))
        return 0;

    while (hour < 0 || hour > 23)
    {
        std::cout << "Hour must be between 0 and 23.\n";
        if (!readIntegerLine("Enter hour (0-23): ", hour))
            return 0;
    }

    if (!readIntegerLine("Enter zone (1=Inner, 2=Middle, 3=Outer): ", zone))
        return 0;

    while (zone < 1 || zone > 3)
    {
        std::cout << "Unknown zone. Choose 1, 2 or 3.\n";
        if (!readIntegerLine("Enter zone (1=Inner, 2=Middle, 3=Outer): ", zone))
            return 0;
    }

    const bool peak = (hour >= 8 && hour < 10) ||
                      (hour >= 17 && hour < 20);
    const long long basePaise[] = {0, 1000, 2000, 3000};
    long long farePaise = basePaise[zone];

    if (peak)
        farePaise += farePaise * 20 / 100;

    std::cout << "\n========== JOURNEY REPORT ==========\n"
              << "Zone       : " << (zone == 1 ? "Inner" :
                                     zone == 2 ? "Middle" : "Outer") << '\n'
              << "Entry hour : " << hour << ":00\n"
              << "Period     : " << (peak ? "Peak" : "Off-peak") << '\n'
              << "Fare       : Rs " << std::fixed << std::setprecision(2)
              << farePaise / 100.0 << '\n'
              << "====================================\n";
}
