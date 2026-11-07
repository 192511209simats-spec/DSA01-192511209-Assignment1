# Predicted output — write this before running

```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

## Line-by-line reasoning

1. `*` has higher precedence than `+`: `5 + (3 * 2) = 11`. Parentheses force `(5 + 3) * 2 = 16`.
2. `x++` yields the old value 5 and then increments `x` to 6. `++y` increments `y` from 3 to 4 and yields 4. Thus `z = 5 + 4 = 9`, and the printed state is `9 6 4`.
3. `x > y` is `6 > 4`, so the conditional operator chooses 6. `%` and `*` have equal precedence and associate left-to-right: `(6 % 4) * 2 = 4`.
4. Integer division truncates toward zero: `10 / 3 = 3`, `-10 / 3 = -3`. The remainder has the sign of the left operand: `10 % 3 = 1`, `-10 % 3 = -1`.
5. The loop adds `i = 0, 3, 6, 9`, giving 18.

Run the program only after recording this prediction. Compare your actual MSVC output with it and attach a screenshot.
