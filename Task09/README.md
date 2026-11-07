# Task 09 – Implement and Test the Fare Logic

## Objective
Implement the original three-zone fare rules and validate normal journeys, peak-hour boundaries, balance rules and invalid inputs.

## Files
- `fare_validation.cpp` – fare engine, recharge validation, input parsing and table-driven tests.
- `test_cases.md` – expected results and manually calculated five-journey example.
- `analysis.md` – alternative test-table approach and complexity.

## Compile and run (MSVC)
Open Developer PowerShell / Developer Command Prompt in this folder:

```powershell
cl /std:c++17 /W4 /EHsc fare_validation.cpp
.\fare_validation.exe
```

The program runs a table-driven test suite. It also checks invalid zone values, negative recharge and non-numeric hour input.

## Fare assumptions
- Inner = ₹10, Middle = ₹20, Outer = ₹30.
- Peak periods are `[08:00, 10:00)` and `[17:00, 20:00)`.
- Peak surcharge = 20%.
- At least ₹50 must remain after a paid journey.
- Student/senior concession percentages are not specified in the assignment, so they are not invented or applied in this implementation.

## Result
The test table reports expected and actual values and marks each case PASS or FAIL. Run the program with MSVC and retain the actual output for your final report.
