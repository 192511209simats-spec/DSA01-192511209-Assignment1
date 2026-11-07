# Task 10 – Compare Expectations with Execution

## Objective
Compare integer-paise and floating-point totals for 20,000, 500,000 and 3,000,000 journeys, and evaluate the limits of `int`, `long long` and `double`.

## Files
- `totals_experiment.cpp` – reproducible accumulation experiment.
- `analysis.md` – formulas, interpretation and complexity comparison.

## Compile and run (MSVC)
```powershell
cl /std:c++17 /W4 /EHsc totals_experiment.cpp
.\totals_experiment.exe
```

## Experiment model
The program uses a fixed, documented distribution:
- 50% Inner, 30% Middle and 20% Outer.
- 25% of journeys occur in peak hours.
- For this experiment, the peak share is applied evenly within each zone.
- No student/senior concession is included because the assignment does not specify rates.

This creates an average fare of ₹17.85 per journey. The experiment is synthetic and intended to compare numeric representations, not to claim actual passenger traffic statistics.

## Compiler note
The assignment mentions `-Wall -Wextra`, which are GCC/Clang options. This repository uses MSVC, so `/W4` is used instead. Record warnings actually shown by your compiler; do not report GCC warnings as if MSVC produced them.
