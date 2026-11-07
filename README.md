# DSA01 – Assignment 1: Metro Smart-Card Fare System

**Course:** Design and Analysis of Algorithms / C++ Programming  
**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Register Number:** 192511209  
**Student Name:** Jason Joshva M J

**Programming Language:** C++  
**Standard:** C++17  
**Compiler:** Microsoft Visual C++ (MSVC)  
**Repository:** https://github.com/192511209simats-spec/DSA01-192511209-Assignment1

---

## 1. Project Overview

This project focuses on designing, implementing and validating the fare calculation logic of a city metro smart-card system using C++.

The metro network consists of three travel zones: Inner, Middle and Outer. Each zone has a fixed base fare. A peak-hour surcharge is applied during specified peak periods, and passengers must maintain a minimum remaining balance of ₹50 after a journey.

The project applies fundamental C++ concepts and object-oriented programming principles to develop a fare system that is accurate, structured, maintainable and scalable.

It also examines how the original design can be adapted to support additional requirements, including an Airport zone, weekend discounts and monthly passes.

## 2. Objectives

- Identify the objects and responsibilities involved in a metro fare system.
- Apply C++ tokens, keywords, identifiers and constants correctly.
- Select appropriate data types and understand type compatibility.
- Analyse implicit conversions and operator precedence.
- Implement fare calculations using operators and control structures.
- Compare procedural and object-oriented programming approaches.
- Handle user input and format program output safely.
- Implement and validate fare calculation logic through test cases.
- Compare expected results with actual program execution.
- Recommend a suitable final system design.
- Evaluate and adapt the design to accommodate new requirements.

## 3. Fare System Requirements

### Base Fare Structure

| Zone | Base Fare |
|---|---:|
| Inner | ₹10 |
| Middle | ₹20 |
| Outer | ₹30 |
| Airport (Design Challenge) | ₹60 |

### Peak Hours

A 20% surcharge applies during:

- Morning: 8:00 AM to 10:00 AM
- Evening: 5:00 PM to 8:00 PM

The start time is inclusive and the end time is exclusive.

### Minimum Balance Rule

A journey is permitted only when the smart card retains at least ₹50 after the fare has been deducted.

### Passenger Concessions

The original scenario mentions concessions for students and senior citizens but does not specify the concession percentages or calculation order. These values are therefore treated as unspecified assumptions rather than fixed fare rules.

## 4. Technologies Used

- **C++17** – Programming language and implementation.
- **Microsoft Visual C++ (MSVC)** – Compiler.
- **Visual Studio / Visual Studio Code** – Development environment.
- **Git** – Version control.
- **GitHub** – Source-code hosting and progressive submission.

## 5. Repository Structure

```text
DSA01-192511209-Assignment1/
│
├── README.md
│
├── Task01/
│   ├── README.md
│   ├── analysis.md
│   └── uml_class_diagram.mmd
│
├── Task02/
│   ├── README.md
│   ├── analysis.md
│   └── constants_demo.cpp
│
├── Task03/
│   ├── README.md
│   ├── analysis.md
│   └── datatype_experiment.cpp
│
├── Task04/
│   ├── README.md
│   ├── analysis.md
│   ├── implicit_conversions.cpp
│   ├── corrected_conversions.cpp
│   └── prediction_before_run.md
│
├── Task05/
│   ├── README.md
│   ├── analysis.md
│   ├── operator_experiment.cpp
│   └── prediction_before_run.md
│
├── Task06/
│   ├── README.md
│   ├── analysis.md
│   ├── fare_control.cpp
│   └── pseudocode.md
│
├── Task07/
│   ├── README.md
│   ├── analysis.md
│   ├── procedural_fare.cpp
│   └── smart_card.cpp
│
├── Task08/
│   ├── README.md
│   ├── analysis.md
│   ├── safe_input_cin.cpp
│   └── safe_input_getline.cpp
│
├── Task09/
│   └── [Implementation and Testing]
│
├── Task10/
│   └── [Expectation vs Execution]
│
├── Task11/
│   └── [Final Design Recommendation]
│
└── Task12/
    └── [Day-4 Design Challenge]
```

*The structure above shows the intended organisation. Add the remaining task files as they are completed.*

## 6. Compilation and Execution

This project uses the Microsoft Visual C++ compiler.

Open the **Developer Command Prompt for Visual Studio** or a terminal configured with the MSVC build tools.

### Compile a program

```powershell
cl /std:c++17 /W4 /EHsc filename.cpp
```

### Execute the generated program

```powershell
.\filename.exe
```

Replace `filename.cpp` with the required source file.

For example:

```powershell
cl /std:c++17 /W4 /EHsc constants_demo.cpp
.\constants_demo.exe
```

The `/W4` option enables a high level of compiler warnings, while `/EHsc` enables standard C++ exception handling.

## 7. Task Summary

| Task | Description | Marks |
|---|---|---:|
| Task 01 | Understand the Problem and Identify the Objects | 4 |
| Task 02 | Tokens, Keywords, Identifiers and Constants | 3 |
| Task 03 | Data Types and Compatibility | 4 |
| Task 04 | Implicit Conversions | 4 |
| Task 05 | Operators and Precedence | 4 |
| Task 06 | Control Structures | 4 |
| Task 07 | Procedural vs Object-Oriented Programming | 4 |
| Task 08 | Input and Output | 4 |
| Task 09 | Implementation and Testing | 4 |
| Task 10 | Expectation vs Execution | 4 |
| Task 11 | Final Design Recommendation | 4 |
| Task 12 | Day-4 Design Challenge | 8 |
| **Total** | | **50** |

Each task is maintained in a separate folder with its corresponding source code and supporting documentation.

## 8. Important Implementation Decisions

- Monetary values are represented using integer paise (`long long`) to avoid floating-point precision errors.
- `enum class` is used to represent metro zones safely.
- `constexpr` constants are used for fixed fare values and system limits.
- Fare calculations use integer arithmetic wherever possible.
- Peak-hour boundaries are handled explicitly.
- Smart-card balance validation ensures that the remaining balance never falls below ₹50 after a successful journey.
- Input validation is used to prevent invalid values from affecting the program.
- Object-oriented design is considered for better encapsulation and maintainability.

## 9. Design Challenge

The final task evaluates how the original fare system can accommodate three additional requirements:

1. **Airport Zone:** Introduces a fourth zone with a base fare of ₹60.
2. **Weekend Discount:** Applies a 10% discount on weekends, which does not combine with the peak-hour surcharge.
3. **Monthly Pass:** Allows unlimited journeys within two selected zones.

The revised design considers the impact of these changes on constants, enumerations, fare calculation logic and smart-card classes. It also evaluates whether the original implementation should be retained, modified or redesigned.

## 10. Version Control and GitHub Submission

The project is maintained using Git and GitHub.

Each task is committed separately to maintain a progressive development history and demonstrate individual task completion.

Example commit messages:

```text
Complete Task 01 - OOP Analysis
Complete Task 02 - Tokens and Constants
Complete Task 03 - Data Types and Compatibility
Complete Task 04 - Implicit Conversions
Complete Task 05 - Operators and Precedence
Complete Task 06 - Control Structures
Complete Task 07 - Procedural vs OOP
Complete Task 08 - Input and Output
```

Further commits are added as the remaining tasks are completed.

## 11. Conclusion

This assignment demonstrates the application of C++ programming concepts and object-oriented design principles to a practical metro smart-card fare system.

Through individual task implementations, testing and design evaluation, the project explores how correct data types, constants, operators and control structures contribute to reliable fare calculations.

The final design challenge further evaluates the system's ability to accommodate changing requirements while maintaining accuracy, scalability and maintainability.

---

**Repository:** https://github.com/192511209simats-spec/DSA01-192511209-Assignment1  
**Assignment:** DSA01 – Assignment 1  
**Language:** C++17


