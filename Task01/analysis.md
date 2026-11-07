# TASK 01 – Understand the Problem and Identify the Objects

**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Task marks:** 4

## 1. Introduction

The Namma Metro Smart-Card Fare System calculates journey fares, applies peak-hour surcharges, maintains passenger card balances and checks whether a passenger is eligible to travel.

The initial metro network contains three zones:

- Inner Zone – ₹10
- Middle Zone – ₹20
- Outer Zone – ₹30

A 20% surcharge applies during peak hours: 08:00–10:00 and 17:00–20:00. A journey is allowed only if at least ₹50 remains on the card after the fare is deducted. Students and senior citizens receive a concession, but the assignment does not specify the concession rates or how concessions interact with peak surcharges.

An object-oriented approach is suitable because the system contains entities with distinct data and responsibilities.

## 2. Identification of Objects

### A. Passenger

**Attributes**
- Passenger ID
- Passenger category: Regular, Student or Senior Citizen

**Behaviour**
- `getPassengerId()`
- `getCategory()`

**Justification:** The Passenger class stores information about the person using the metro. A category attribute identifies concession eligibility. This design avoids unnecessary subclasses when the requirements do not define different passenger-specific behaviour.

### B. SmartCard

**Attributes**
- Card ID
- Card balance

**Behaviour**
- `recharge()`
- `deduct()`
- `canTravel()`
- `getBalance()`

**Justification:** SmartCard manages the stored monetary balance. The balance should be private so that other parts of the program cannot modify it directly. Controlled methods validate recharges and deductions, helping preserve the minimum-balance rule.

### C. Journey

**Attributes**
- Source zone
- Destination zone
- Departure time
- Calculated fare

**Behaviour**
- `recordJourney()`
- `getFare()`

**Justification:** Journey represents an individual metro trip. It stores the information required to calculate the fare and maintain a journey record.

### D. Zone

**Values**
- Inner
- Middle
- Outer

**Justification:** Zone represents the metro travel zones. It can be implemented using `enum class` to restrict accepted zone values and improve type safety.

### E. FareTable

**Attributes**
- Base fare for each zone
- Peak surcharge percentage

**Behaviour**
- `getBaseFare()`
- `getSurchargePercent()`

**Justification:** FareTable centralises fare values. If the metro revises its fare structure, the values can be updated in one place rather than changed at several locations in the program.

### F. FareCalculator

**Behaviour**
- `calculateFare()`
- `isPeakHour()`

**Justification:** FareCalculator handles fare computation separately from card management. It obtains the base fare from FareTable and applies the peak surcharge when applicable.

## 3. Procedural Programming vs Object-Oriented Programming

### Procedural approach

In procedural programming, the system can be implemented using separate variables and free functions. Variables store the card balance, passenger category and zone. Functions calculate the fare, check whether the passenger can travel and deduct the fare.

This approach is straightforward for a small program. However, as the system grows, several functions may access and modify shared data, making maintenance and data protection more difficult.

Example of a procedural interface:

```cpp
int cardBalance = 10000;
int passengerType = 1;
int zone = 2;

int calculateFare(int zone, bool peak);
bool canTravel(int balance, int fare);
void deductFare(int& balance, int fare);
```

### Object-oriented approach

In object-oriented programming, related data and behaviour are grouped into classes. For example, SmartCard stores the balance and provides methods to recharge, check eligibility and deduct fares.

This provides better organisation, data protection and separation of responsibilities. Fare calculation, journey management and card management can be maintained independently.

| Feature | Procedural programming | Object-oriented programming |
|---|---|---|
| Structure | Functions and variables | Classes and objects |
| Data management | Separate variables | Data grouped within objects |
| Data protection | Depends on program design | Access control through encapsulation |
| Reusability | Functions | Classes and objects |
| Maintenance | Can become difficult as the system grows | Responsibilities can be separated |
| Scalability | Requires careful organisation | Supports modular expansion |

Both approaches can achieve the same computational efficiency. OOP is preferred here mainly because it provides better organisation and control over important system rules.

## 4. Four Fundamental Principles of OOP

### A. Encapsulation

Encapsulation combines data and methods inside a class and restricts direct access to important data.

In this system, SmartCard keeps its balance private. The balance can be modified only through controlled methods such as `recharge()` and `deduct()`. This helps prevent unauthorised balance changes and invalid deductions.

### B. Abstraction

Abstraction hides internal implementation details and exposes only necessary operations.

For example, the gate system can call `calculateFare()` without knowing all the internal steps involved in calculating the base fare and applying the peak surcharge.

### C. Inheritance

Inheritance allows a derived class to acquire attributes and methods from a base class.

A possible design could have Student and SeniorCitizen inherit from a base Passenger class. However, this design uses a passenger category attribute instead because the initial requirements do not justify separate subclasses.

### D. Polymorphism

Polymorphism allows different objects to respond differently to the same interface.

For example, different concession policies could implement a common fare-adjustment operation for student and senior-citizen passengers. However, the exact concession rates and calculation rules are not provided in the assignment. Implementing these policies requires clarification of those rules.

## 5. Rules and Constraints of the System

The following rules must be maintained:

1. **Minimum balance:** At least ₹50 must remain on the smart card after a successful journey.
2. **Non-negative balance:** The card balance must never become negative.
3. **Valid zone:** Only the defined zones are accepted in the initial system.
4. **Peak-hour surcharge:** A 20% surcharge applies from 08:00 to 10:00 and 17:00 to 20:00.
5. **Time boundaries:** The starting time of a peak interval is included, while its ending time is excluded.
6. **Correct fare:** The fare must correspond to the farthest zone travelled.
7. **Controlled balance modification:** The card balance must be modified only through authorised methods.

## 6. Alternative Concept and Complexity Analysis

If the system were implemented using a purely procedural approach, global variables could store passenger details, card balance and fare values. Free functions could calculate fares, validate journeys and deduct balances.

The time and space complexities of both approaches are comparable.

| Operation | Procedural approach | OOP approach |
|---|---:|---:|
| Fare calculation | O(1) | O(1) |
| Balance validation | O(1) | O(1) |
| Fare deduction | O(1) | O(1) |
| Balance storage per card | O(1) | O(1) |

**Time complexity:** Both approaches require constant time, O(1), for an individual fare calculation and balance validation.

**Space complexity:** Both approaches require constant space, O(1), to store the balance of one card, excluding journey history and other stored records.

**Maintenance comparison:** In a procedural design, a change to a fare rule may require modifications in multiple functions if the rule is duplicated. In the object-oriented design, centralising fare values in FareTable and calculation rules in FareCalculator limits changes to the relevant components.

However, a properly structured procedural program can also centralise these rules. OOP does not automatically guarantee fewer modifications; its main advantage is organising related responsibilities and protecting data.

## 7. Conclusion

The object-oriented approach is suitable for the Namma Metro Smart-Card Fare System because it separates passenger details, smart-card balance management, journey records and fare calculations into independent responsibilities.

Encapsulation protects the card balance, abstraction hides internal calculation details, inheritance can represent specialised passenger types, and polymorphism can support different concession policies.

Although procedural and object-oriented approaches have similar time and space complexities for individual journeys, the object-oriented design provides a modular and maintainable structure that can support future changes to the metro fare system.

## 8. Assumptions and Unspecified Requirements

| Item | Treatment |
|---|---|
| Student concession rate | Not specified in the assignment |
| Senior-citizen concession rate | Not specified in the assignment |
| Order of concession and peak surcharge | Not specified in the assignment |
| Passenger-to-card relationship | UML proposes one passenger may use zero or more cards; confirm if needed |
| Journey history | UML proposes that a card can record multiple journeys |

No concession percentage or calculation order has been invented. These details must be clarified before implementing concession calculations.
