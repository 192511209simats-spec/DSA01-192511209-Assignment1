# Task 12 – Re-evaluate and Adapt the Design

## Objective
Adapt the original three-zone fare system to support:
- Airport zone with a ₹60 base fare.
- 10% weekend discount that does not combine with the peak surcharge.
- Monthly pass allowing unlimited journeys in two selected zones.

## Files
- `adapted_metro.cpp` – revised fare table, discount policy, SmartCard and MonthlyPass.
- `design_evaluation.md` – impact analysis, worked examples, trade-offs and defence.

## Compile and run (MSVC)
```powershell
cl /std:c++17 /W4 /EHsc adapted_metro.cpp
.\adapted_metro.exe
```

## Explicit assumptions
- The weekend discount replaces the peak surcharge; the two are never combined.
- Weekend discount is applied to the base fare and rounded to the nearest paise using integer arithmetic. All current example fares produce whole-rupee results.
- A valid monthly pass covers exactly two selected zones, is valid for the simulated month and waives the fare for journeys in those zones.
- The ₹50 minimum balance rule remains in force after each journey, including a pass-covered journey (where the fare is zero).
- The assignment does not define pass price, expiry date handling, refund rules or concession stacking; those are outside this prototype.

## Result
The program demonstrates regular, peak, weekend-discount and pass-covered journeys and prints whether each journey is accepted. Execute it locally and record the actual output for your final report.
