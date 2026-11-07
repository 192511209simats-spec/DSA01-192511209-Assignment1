# TASK 03 – Choose Data Types and Check Type Compatibility

**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Task marks:** 4

## 1. Introduction

The metro fare system stores passenger balances, fares, journey times, zone values and journey counts. Choosing suitable C++ data types is important for accuracy, range and memory use.

Money should be stored as integer paise using `long long`, rather than floating-point rupees, to avoid rounding errors in financial calculations.

## 2. Recommended Data Types

| Value | Recommended type | Reason |
|---|---|---|
| Peak-hour flag | `bool` | Represents true or false |
| Single character code, if required | `char` | Stores one character |
| Departure hour | `int` | Stores values from 0 to 23 |
| Zone | `enum class Zone : int` | Represents a fixed set of named zones with type safety |
| Base fare and balance | `long long` | Stores money exactly as integer paise and provides a large range |
| Journey count | `unsigned long long` | Represents a non-negative count |
| Approximate measurement, if ever needed | `float` | Lower precision; not suitable for money |
| Alternative money representation | `double` | Floating-point alternative examined in this task, but not recommended for exact money |
| Local value whose type is obvious from its initializer | `auto` | Lets the compiler deduce the type |

`auto` is a type-deduction keyword, not a separate storage type. The compiler deduces the variable's actual type from its initializer.

## 3. Why Money Should Be Stored in Integer Paise

Using `double` to store rupees can introduce binary floating-point representation and accumulation errors for decimal fractions.

For example, a decimal value such as 0.1 cannot be represented exactly in binary floating-point. Repeated additions can therefore produce a result that differs slightly from the intended decimal total.

Instead, store money in paise:

- ₹10.00 = 1000 paise
- ₹20.00 = 2000 paise
- ₹30.00 = 3000 paise
- ₹50.00 = 5000 paise

For example:

```cpp
long long balancePaise = 10000; // Rs 100.00
long long farePaise = 1200;     // Rs 12.00
balancePaise -= farePaise;
```

Integer arithmetic keeps the monetary values exact as long as the chosen integer type does not overflow.

## 4. Type Compatibility

C++ applies conversions when different types are used in the same expression.

### Integer and double

When an integer and a `double` are used in an arithmetic expression, the integer is normally converted to `double`.

```cpp
int count = 5;
double amount = 2.5;
double result = count + amount; // count converted to double
```

The result is `7.5`.

### Integer and bool

A Boolean value can be converted to an integer:

- `false` becomes `0`.
- `true` becomes `1`.

A numeric value converted to `bool` becomes `false` if it is zero and `true` otherwise.

### Signed and unsigned

When signed and unsigned integer values of the same rank are compared, the usual arithmetic conversions can convert the signed value to unsigned. A negative signed value can then become a very large unsigned value, causing surprising comparison results.

The program in Task 04 demonstrates this behaviour.

## 5. Ranges from <climits>

The `<climits>` header provides limits for fundamental integer types.

Important macros include:

- `INT_MIN` and `INT_MAX` – minimum and maximum values of `int`.
- `UINT_MAX` – maximum value of `unsigned int`.
- `LLONG_MIN` and `LLONG_MAX` – minimum and maximum values of `long long`.
- `CHAR_MIN` and `CHAR_MAX` – limits of `char`.

The exact sizes and ranges should be measured on the compiler and system used for submission. The accompanying C++ program prints `sizeof` values and the limits reported by the user's compiler.

## 6. Is int Enough for a Day's Network Collection?

The network may process 3,000,000 journeys per day.

For a conservative upper-bound illustration, assume every journey is an Outer Zone peak journey:

- Base fare = ₹30
- 20% surcharge = ₹6
- Maximum illustrated fare = ₹36 = 3600 paise
- Journeys per day = 3,000,000

Maximum illustrated daily collection:

`3,000,000 × 3600 = 10,800,000,000 paise`

A typical 32-bit signed `int` has a maximum value of 2,147,483,647, so it cannot hold this total in paise. A `long long` is appropriate.

If the total were stored in whole rupees, ₹108,000,000 would fit in a typical 32-bit signed `int`. However, this system stores money in paise to preserve exactness, so `int` is insufficient for the illustrated network total.

This is an upper-bound calculation, not a claim that every actual journey has the maximum fare.

## 7. Alternative Concept and Complexity Analysis: double Rupees

If money were stored as `double` rupees instead of `long long` paise:

- Each addition still takes O(1) time.
- A `double` commonly occupies 8 bytes.
- A `long long` commonly occupies 8 bytes.
- Floating-point representation can introduce small rounding errors for decimal fractions.
- Integer paise provides exact addition for values represented as whole paise, provided overflow is avoided.

The accompanying program performs an illustrative repeated-addition experiment using ₹0.10. This is a precision demonstration, not an assumed metro fare or concession value. The assignment's actual base fares and 20% surcharge produce whole-rupee amounts. Those particular amounts can be represented exactly as `double` at the stated journey volumes, but integer paise remains the safer financial representation, especially if future rules introduce fractional-paise calculations or more complex adjustments.

## 8. Conclusion

The recommended design uses `long long` for money stored in paise, `int` for time values, `bool` for logical flags, `enum class` for zones and `unsigned long long` for non-negative journey counts. `float` and `double` are not recommended for exact financial storage. The measured `sizeof` values and integer limits should be taken from the actual compiler used for submission. For the stated network scale, `long long` is required to safely accumulate the illustrated daily collection in paise.
