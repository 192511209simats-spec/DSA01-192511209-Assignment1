# TASK 04 – Control Implicit Conversions

**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Task marks:** 4

## 1. Introduction

An implicit conversion occurs when C++ automatically converts a value from one type to another. These conversions can affect arithmetic, comparisons, initialisation and output.

The metro fare program must use conversions carefully, especially when handling money and comparing signed and unsigned values.

## 2. Integer Division and Integer-to-Double Conversion

Consider:

```cpp
int a = 7, b = 2;
double c = a / b;
```

Both operands are integers, so integer division takes place first. The result is `3`, because the fractional part is discarded. This integer result is then converted to `double`, so `c` stores `3.0`.

To obtain `3.5`, convert one operand before division:

```cpp
double d = static_cast<double>(a) / b;
```

Here, `a` is converted to `double` before division, so floating-point division produces `3.5`.

## 3. Character-to-Integer Promotion

```cpp
char ch = 'A' + 2;
std::cout << ch << ' ' << ch + 1;
```

The character literal `'A'` is promoted to an integer for arithmetic. Adding 2 gives the character code for `C`, which is stored in `ch`.

When `ch + 1` is evaluated, `ch` is promoted to `int`. On systems using the usual ASCII-compatible character set, the result is `68`. The first output is the character `C`; the second is the integer value `68`.

## 4. Integer-to-Bool Conversion

```cpp
bool flag = 5;
std::cout << flag << ' ' << std::boolalpha << flag;
```

A non-zero integer converts to `true`. By default, a Boolean is printed as `1` or `0`. After applying `std::boolalpha`, it is printed as `true` or `false`.

Therefore, this line prints:

`1 true`

## 5. Signed and Unsigned Comparison

```cpp
unsigned int u = 1;
int s = -1;
std::cout << (s < u ? "s < u" : "s >= u");
```

The comparison applies the usual arithmetic conversions. In this case, the negative signed integer is converted to `unsigned int`. Its value becomes a large unsigned value, so the comparison `s < u` is false and the conditional expression selects `"s >= u"`.

A compiler may warn about comparing signed and unsigned values. With MSVC, check the actual diagnostic under the selected warning level; a common diagnostic is C4018 (signed/unsigned mismatch). Warning behaviour should be recorded from the compiler actually used.

## 6. Narrowing Conversions and Brace Initialisation

A conversion that cannot safely preserve the original value is called a narrowing conversion in contexts such as list initialisation.

This is rejected by the compiler:

```cpp
// int x{3.7}; // Compile-time error: narrowing conversion
```

Brace initialisation helps detect unintended narrowing at compile time.

If truncation is genuinely intended, it should be explicit and justified:

```cpp
int wholePart = static_cast<int>(3.7); // Produces 3 by truncation
```

## 7. Use of static_cast

`static_cast` makes an intended conversion explicit.

For example:

```cpp
double precise = static_cast<double>(7) / 2;
```

This produces `3.5` because the conversion occurs before division.

Explicit conversions make the programmer's intention clearer and help avoid accidental conversions.

## 8. Predicted Output of the Given Program

The required prediction is recorded separately in `prediction_before_run.md`. It must be written before compiling or running the original program.

Expected prediction:

```text
3 3.5
C 68
1 true
s >= u
```

## 9. Corrected Version Using Explicit Conversions

A safer version can make important conversions explicit:

```cpp
int a{7};
int b{2};

double c{static_cast<double>(a) / b};

char ch{static_cast<char>('A' + 2)};

bool flag{5 != 0};

unsigned int u{1};
int s{-1};

// Widen the unsigned value to long long before comparison.
// Every unsigned int value fits in long long on standard-conforming
// implementations where long long has at least 64 bits.
bool signedComparison = static_cast<long long>(s)
                      < static_cast<long long>(u);
```

For this example, the comparison is now a signed comparison after widening both operands. It avoids converting the negative `s` to unsigned.

## 10. Alternative Concept and Complexity Analysis

If all intended conversions were written explicitly using `static_cast` and brace initialisation were used, the program would communicate conversions more clearly.

- Time complexity remains O(1) for the individual expressions.
- Space complexity remains O(1); the same variables are stored.
- Brace initialisation rejects certain narrowing conversions at compile time.
- Explicit casts make intentional conversions visible, but they do not automatically make an unsafe conversion safe. The programmer must still validate the value and choose the correct target type.

This approach helps detect some errors during compilation rather than allowing unintended values to reach runtime.

## 11. Conclusion

Implicit conversions can produce unexpected results, especially with integer division, character promotion, Boolean conversion and signed/unsigned comparisons. Using `static_cast` when conversion is intentional and brace initialisation where suitable makes the program clearer and helps the compiler detect narrowing errors. These practices are important in a fare system where correctness and exact values matter.
