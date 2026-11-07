# Task 09 – Analysis

## Implementation
The fare logic uses a switch to select the base fare and integer paise arithmetic to apply the 20% peak surcharge. The peak test uses half-open intervals: `[8,10)` and `[17,20)`. `canTravel` checks that the post-fare balance is at least 5000 paise. Invalid zones return `-1`; negative recharges and invalid hour text are rejected.

## Table-driven tests – alternative
Instead of writing a separate assertion for every input, test cases can be stored in an array/vector containing the input, expected fare and expected permission. A loop executes the same calculation for each record. This is the approach used in `fare_validation.cpp`.

## Complexity
Let `t` be the number of test cases.
- One fare calculation: O(1) time and O(1) auxiliary space.
- Running the complete test suite: O(t) time.
- Test table storage: O(t) space.
- Adding a boundary test: append one record, without duplicating test logic.

A table-driven approach is easier to extend and keeps the validation procedure consistent. Its main cost is memory proportional to the number of test cases.
