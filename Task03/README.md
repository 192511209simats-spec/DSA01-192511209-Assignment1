# Task 03 – Data Types and Type Compatibility

## Files
- `analysis.md` – Data-type selection, money representation, conversions, integer limits, network-total calculation and complexity comparison.
- `datatype_experiment.cpp` – Prints `sizeof` values and `<climits>` ranges on the compiler used, checks the illustrated network total, and compares repeated `double` additions with integer-paise accumulation.

## Compile and run with Microsoft Visual C++

Open a **Developer Command Prompt for Visual Studio**, navigate to this folder, and run:

```bat
cl /std:c++17 /W4 /EHsc datatype_experiment.cpp
datatype_experiment.exe
```

Save the actual console output or a screenshot after running it. Copy the measured `sizeof` values and ranges into the report. Do not assume values without executing on the submission system.

## Important interpretation

The floating-point experiment uses repeated additions of ₹0.10 solely to demonstrate binary floating-point accumulation. It is not an assumed metro fare or concession. The actual stated fares and 20% surcharge are whole-rupee values. The network total check uses an illustrative upper bound of ₹36 per journey and stores the total in paise.
