#include <iostream>

constexpr long long MIN_BALANCE_PAISE = 5000;

class SmartCard
{
private:
    long long balancePaise;

public:
    explicit SmartCard(long long openingBalance)
        : balancePaise(openingBalance >= 0 ? openingBalance : 0) {}

    bool canTravel(long long farePaise) const
    {
        return farePaise >= 0 &&
               balancePaise >= farePaise &&
               balancePaise - farePaise >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long farePaise)
    {
        if (!canTravel(farePaise))
            return false;

        balancePaise -= farePaise;
        return true;
    }

    long long getBalance() const
    {
        return balancePaise;
    }
};

int main()
{
    SmartCard card(10000);
    const long long fares[] = {1000, 3600, 2000};

    for (long long fare : fares)
    {
        if (card.deduct(fare))
            std::cout << "Accepted";
        else
            std::cout << "Denied";

        std::cout << " | balance = " << card.getBalance()
                  << " paise\n";
    }
}
