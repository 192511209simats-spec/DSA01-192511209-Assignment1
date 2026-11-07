# Task 05 – Correct Expressions and Operator Precedence

## 1. Peak-hour check

```cpp
bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}
```

The ranges are half-open: 08:00 and 17:00 are peak; 10:00 and 20:00 are not. The parentheses make the two intervals explicit. `&&` binds more tightly than `||`, so the unparenthesized expression in the question is logically equivalent, but less easy to scan.

For a system that accepts minutes, represent time as minutes after midnight and compare against `[480,600)` and `[1020,1200)` to avoid treating every minute within an hour as identical.

## 2. Surcharge in integer paise

```cpp
long long finalFare = baseFare;
if (isPeak(hour)) {
    finalFare += baseFare * PEAK_SURCHARGE_PERCENT / 100;
}
```

Multiplication and division occur before compound assignment. With the specified base fares (1000, 2000, 3000 paise), the 20% amount is exact. In general, if a percentage can create fractional paise, define and document a rounding rule.

## 3. Concession

The brief says students and senior citizens receive a concession but gives no percentage or precedence rule. Do not invent a numeric rate. Once the instructor confirms a concession percentage `C`, a possible formula is:

```cpp
discountedFare = baseFare * (100 - C) / 100;
```

The system must also specify whether concession is applied before or after peak surcharge and how paise rounding works. Those rules affect the result.

## 4. Operators and evaluation

- `x++`: yields the old value, then increments.
- `++x`: increments first, then yields the new value.
- Avoid `i = i++`. It is confusing and has historically involved sequencing pitfalls; write `i++` or `++i` as a separate statement.
- `/` with integers performs integer division; the fractional part is discarded by truncation toward zero.
- `%` gives the remainder. For `-10 / 3`, the quotient is `-3` and the remainder is `-1`.
- `?:` evaluates the condition and yields one of two expressions.
- `+=` adds the right-hand value and stores the result in the left operand.
- Multiplication and division bind more tightly than addition/subtraction; relational operators bind more tightly than `&&`; `&&` binds more tightly than `||`.

## 5. Alternative: 24-hour lookup table

A `bool peak[24]` table can be initialized once and queried as `peak[hour]`. Both the expression and table lookup take O(1) time. The table uses 24 boolean elements (commonly 24 bytes, though `sizeof(bool)` is implementation-defined). It may reduce repeated comparisons, but the interval expression is simpler to maintain and uses no table storage. A table must be updated carefully if peak periods change.

## Complexity

A peak check and fare expression each take O(1) time and O(1) auxiliary space. The lookup-table alternative also takes O(1) time, with O(24) = O(1) fixed storage.
