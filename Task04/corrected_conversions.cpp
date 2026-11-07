#include <iostream>

int main()
{
    int a{7};
    int b{2};

    // Convert before division to obtain floating-point division.
    double c{static_cast<double>(a) / b};

    // Make the character conversion explicit.
    char ch{static_cast<char>('A' + 2)};

    // Make the integer-to-bool intention explicit.
    bool flag{5 != 0};

    unsigned int u{1};
    int s{-1};

    // Widen both values to a signed type before comparing.
    bool signedComparison =
        static_cast<long long>(s) < static_cast<long long>(u);

    std::cout << c << '\n';
    std::cout << ch << ' '
              << static_cast<int>(ch) + 1 << '\n';
    std::cout << std::boolalpha << flag << '\n';
    std::cout << (signedComparison ? "s < u" : "s >= u") << '\n';

    return 0;
}
