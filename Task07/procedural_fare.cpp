#include <iostream>

constexpr long long MIN_BALANCE_PAISE = 5000;

bool canTravel(long long balance, long long fare)
{
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE_PAISE;
}

bool deduct(long long& balance, long long fare)
{
    if (!canTravel(balance, fare))
        return false;

    balance -= fare;
    return true;
}

int main()
{
    long long balance = 10000;
    const long long fares[] = {1000, 3600, 2000};

    for (long long fare : fares)
    {
        if (deduct(balance, fare))
            std::cout << "Accepted";
        else
            std::cout << "Denied";

        std::cout << " | balance = " << balance << " paise\n";
    }
}
