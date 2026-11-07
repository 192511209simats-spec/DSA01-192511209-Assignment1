# Task 07 – Procedural and Object-Oriented Designs

## Procedural version

The procedural program stores the balance in a local variable and passes it by reference to free functions `canTravel()` and `deduct()`. The functions check the fare and minimum remaining balance before changing the variable.

## Object-oriented version

`SmartCard` stores `balancePaise` as a private data member. Other code cannot directly assign a negative balance or bypass the fare check. The public `canTravel()`, `deduct()` and `getBalance()` methods provide controlled access.

## Why the class protects the invariant

The invariant is: a successful journey must leave at least 5000 paise (₹50) on the card. `deduct()` changes the private balance only after `canTravel()` succeeds. A negative fare is also rejected. The constructor normalizes a negative opening balance to zero; in a stricter production design, it could instead report invalid construction.

## Which is easier to change?

The OOP version centralizes the minimum-balance rule inside `SmartCard`. Changing the threshold requires changing one class constant/rule. In the procedural version, every function or code path that changes the balance must follow the same rule. Both can be correct, but the class makes accidental bypass harder.

## Alternative: public balance

If `balancePaise` were public, any part of the program could write `card.balancePaise = -100` or subtract a fare without checking the ₹50 minimum. Encapsulation prevents this category of invariant violation. Making it public does not materially change asymptotic time or storage: both designs use O(1) time for a deduction and O(1) balance storage per card. The difference is safety and maintainability, not Big-O performance.

## Complexity

`canTravel()` and `deduct()` are O(1) time. The card stores one balance value, O(1) space. Processing `n` fares in the demonstration loop is O(n) time.
