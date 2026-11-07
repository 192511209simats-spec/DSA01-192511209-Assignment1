# Task 02 – Tokens, Keywords, Identifiers and Constants

## Files
- `analysis.md` – Written explanation of the five token categories, `#define`, `const`, `constexpr`, `enum`, `enum class`, naming conventions and complexity comparison.
- `constants_demo.cpp` – Small C++17 program demonstrating the selected fare constants and scoped zone enumeration.

## Compile and run (Microsoft Visual C++)

Open a **Developer Command Prompt for Visual Studio**, navigate to this folder, and run:

```bat
cl /std:c++17 /W4 /EHsc constants_demo.cpp
constants_demo.exe
```

Record the actual compiler version and output from your own Visual Studio installation in the final assignment README/report. Do not claim a compiler version or execution result until you have run it locally.

## Expected demonstration

The program prints the three base fares in paise, the peak surcharge percentage, the minimum remaining balance in paise, and the selected zone.

## Note
The assignment does not provide concession percentages or the order of concession and peak surcharge. Those details are not assumed here.
