# Task 10 – Expectation vs Execution

## Expected totals

The experiment fixes an average fare of ₹17.85 (1785 paise) per journey. It is derived from an explicitly assumed distribution:

- Base fare average: `0.50(₹10) + 0.30(₹20) + 0.20(₹30) = ₹17.00`.
- 25% peak share with a 20% surcharge: `₹17.00 × (1 + 0.25 × 0.20) = ₹17.85`.

| Journeys | Expected total (paise) | Expected total (rupees) |
|---:|---:|---:|
| 20,000 | 35,700,000 | ₹357,000.00 |
| 500,000 | 892,500,000 | ₹8,925,000.00 |
| 3,000,000 | 5,355,000,000 | ₹53,550,000.00 |

The 3,000,000-journey total exceeds the typical signed 32-bit `int` maximum of 2,147,483,647 paise. Do not deliberately perform signed overflow: in C++, signed integer overflow is undefined behaviour. The program checks the threshold mathematically.

## Integer paise vs double rupees
- Integer paise gives exact totals for fares expressed in whole paise, provided the chosen integer type does not overflow.
- `double` stores binary floating-point values. Decimal values such as 17.85 are not generally represented exactly, so repeated additions can produce a small rounding difference.
- The exact difference is platform/compiler/runtime dependent; use the output of your own run rather than copying a fabricated measurement.

## Type comparison at 3,000,000 journeys

| Type | Typical size | Behaviour |
|---|---:|---|
| `int` | 4 bytes | Cannot safely hold 5,355,000,000 paise on a typical 32-bit signed int |
| `long long` | 8 bytes | Holds this total comfortably |
| `double` | 8 bytes | Large range and approximate decimal representation; small rounding error possible |

Each addition is O(1) time. The accumulation loop is O(n) time and O(1) extra space. `long long` is recommended for exact monetary totals at this scale.

## Compiler warnings
The assignment's `-Wall -Wextra` flags belong to GCC/Clang. This project is compiled with MSVC `/W4`. Compiler diagnostics vary by compiler and version. Record the warnings actually produced by your installed MSVC; do not claim that a warning occurred if it did not.
