# Task 04 – Predicted Output (write before execution)

**Important:** This is the prediction for the original program supplied in the assignment. Record it before compiling or running that program.

## My predicted output

```text
3 3.5
C 68
1 true
s >= u
```

## Reasoning behind the prediction

1. `a / b` performs integer division because both operands are `int`. `7 / 2` produces `3`, which is then converted to `double` and printed as `3`. The explicit cast in the second expression causes floating-point division and produces `3.5`.
2. `'A' + 2` uses integer promotion during arithmetic and produces the character `C`. In `ch + 1`, `ch` is promoted to `int`, so the numeric character value plus one is printed. On an ASCII-compatible system, this is `68`.
3. The non-zero integer `5` converts to `true`. The first Boolean output is printed as `1`; after `std::boolalpha`, it is printed as `true`.
4. In `s < u`, the negative signed integer is converted to unsigned for the comparison. It becomes a large unsigned value, so the condition is false and the program prints `s >= u`.

## Actual output and compiler diagnostic

Leave this section blank until the original program has been compiled and run on the submission system.

- Actual output:
- Compiler warning(s), if any:
- Differences from prediction:
- Explanation of any differences:

Do not fill the actual-output section using the prediction. Attach a screenshot of the actual run after execution.
