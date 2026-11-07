# TASK 02 – Use Tokens, Keywords, Identifiers and Constants Correctly

**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Task marks:** 3

## 1. Introduction

In the Namma Metro Smart-Card Fare System, fares, peak-hour surcharge and minimum balance should be defined centrally so that changes can be made in one place. C++ provides keywords, identifiers, constants and enumerations to organise these values safely.

## 2. Five Types of Tokens

A token is the smallest meaningful unit recognised by the C++ compiler.

| Token type | Examples | Description |
|---|---|---|
| Keywords | `int`, `class`, `constexpr`, `return` | Reserved words with predefined meanings |
| Identifiers | `cardBalance`, `calculateFare`, `MIN_BALANCE_PAISE` | Names given to program elements |
| Constants/literals | `1000`, `20`, `true`, `'A'` | Fixed values used in the program |
| Operators | `+`, `-`, `=`, `==` | Symbols that perform operations |
| Punctuators | `;`, `{}`, `()`, `[]` | Symbols used to structure the program |

For example:

```cpp
constexpr int BASE_FARE = 1000;
```

Here, `constexpr` and `int` are keywords, `BASE_FARE` is an identifier, `1000` is an integer literal, `=` is an assignment operator and `;` is a punctuator.

## 3. Comparison of #define, const and constexpr

### #define

`#define` is a preprocessor directive that performs textual substitution before compilation.

```cpp
#define INNER_FARE 1000
#define PEAK_SURCHARGE 20
```

It does not provide normal C++ type checking or scope control.

### const

`const` declares a variable whose value cannot be modified after initialisation.

```cpp
const int INNER_FARE = 1000;
```

It follows normal C++ type and scope rules.

### constexpr

`constexpr` declares a value that can be used in constant expressions and is evaluated at compile time when required.

```cpp
constexpr int INNER_FARE = 1000;
constexpr int PEAK_SURCHARGE = 20;
```

It is preferred for the metro fare values because these values are known during compilation and should remain fixed.

| Feature | #define | const | constexpr |
|---|---|---|---|
| Type checking | No normal type checking | Yes | Yes |
| Scope | Preprocessor substitution | C++ scope | C++ scope |
| Compile-time constant | Text substitution | Not necessarily | Yes |
| Recommended for fare values | No | Acceptable | Preferred |

## 4. enum and enum class

An enumeration represents a fixed set of named values.

Traditional enum:

```cpp
enum Zone {
    Inner,
    Middle,
    Outer
};
```

Scoped enumeration:

```cpp
enum class Zone {
    Inner,
    Middle,
    Outer
};
```

`enum class` is preferred because its values are scoped and do not implicitly convert to integers. It provides better type safety and reduces naming conflicts.

For example:

```cpp
Zone destination = Zone::Outer;
```

## 5. Naming Rules and Conventions

Identifiers are names assigned to variables, functions, classes and other program elements.

The following naming conventions are used:

- Variables use camelCase, such as `cardBalance`.
- Functions use descriptive names, such as `calculateFare()`.
- Class names use PascalCase, such as `SmartCard`.
- Constants use uppercase letters with underscores, such as `MIN_BALANCE_PAISE`.

Identifier rules:

1. An identifier cannot begin with a digit.
2. It cannot contain spaces.
3. It cannot be a reserved C++ keyword.
4. It can contain letters, digits and underscores.
5. Identifiers are case-sensitive.

## 6. Recommended Constant Definitions

The following definitions centralise the metro fare values:

```cpp
enum class Zone {
    Inner,
    Middle,
    Outer
};

constexpr long long BASE_PAISE[] = {
    1000,
    2000,
    3000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;

constexpr long long MIN_BALANCE_PAISE = 5000;
```

The fare values are stored in paise rather than floating-point rupees to avoid rounding errors. The use of `constexpr` ensures that the fixed fare values can be used in compile-time expressions.

## 7. Alternative Concept and Complexity Analysis

If `#define` macros were used instead of `constexpr` constants and `enum class`, the program would rely on textual substitution and would lose normal type checking and scope control for those definitions.

Macros do not require storage themselves. Compile-time constants also generally do not require separate runtime storage in this implementation.

Both approaches provide constant-time access to fixed fare values, so the time complexity remains O(1). There is no meaningful difference in runtime space complexity for these definitions.

However, `constexpr` and `enum class` provide safer and more maintainable code because they support type checking, scope control and clearer program organisation.

## 8. Conclusion

The metro fare system should use `constexpr` for fixed fare values, surcharge percentages and minimum balance limits. The zones should be represented using `enum class` to improve type safety and avoid naming conflicts. Consistent identifier naming conventions make the program easier to understand and maintain. This approach is safer and more suitable for future changes than using preprocessor macros.
