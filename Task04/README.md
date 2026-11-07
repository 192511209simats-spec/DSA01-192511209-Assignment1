# Task 04 – Control Implicit Conversions

## Files
- `analysis.md` – Explanation of integer division, integer-to-double conversion, character promotion, integer-to-bool conversion, signed/unsigned comparison, narrowing, `static_cast` and complexity.
- `implicit_conversions.cpp` – Original program from the assignment, preserved for prediction and execution.
- `corrected_conversions.cpp` – Example using explicit conversions and brace initialisation.
- `prediction_before_run.md` – Predicted output and reasoning. This must be reviewed and retained before running the original program.

## Compile and run with Microsoft Visual C++

Open a **Developer Command Prompt for Visual Studio**, navigate to this folder, and run:

```bat
cl /std:c++17 /W4 /EHsc implicit_conversions.cpp
implicit_conversions.exe
```

Then compile the corrected version separately:

```bat
cl /std:c++17 /W4 /EHsc corrected_conversions.cpp
corrected_conversions.exe
```

Record the actual output and warnings from your compiler. MSVC warning behaviour can differ from GCC's `-Wall -Wextra`; do not report GCC warnings unless you actually compile with GCC.

## Required evidence

- Preserve `prediction_before_run.md` as the pre-execution prediction.
- Capture a screenshot of the original program's actual output.
- Record any compiler warning, including its code and meaning, if emitted.
- Compare the actual output with the prediction.
