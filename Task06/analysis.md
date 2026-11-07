# Task 06 – Design the Control Structures

## Why each structure is used

- `switch`: selects one base fare from the mutually exclusive zone values. Every valid enum value has a case, and `default` rejects an unexpected value.
- `if/else`: checks peak status and whether the balance after fare deduction remains at least ₹50.
- Conditional operator `?:`: suitable for a short value selection, but a multi-branch fare calculation is clearer with `switch`.
- Range-based `for`: best for processing every item in a known array/container without manually managing an index.
- Traditional `for`: useful when an index or exact numeric range is needed.
- `while`: useful when the number of journeys is not known in advance, such as reading until the operator enters a quit command.
- `continue`: skip an invalid journey and proceed to the next one.
- `break`: exit a loop when a stop condition is reached, or exit a `switch` case so execution does not fall through.

## No matching switch case

If no case matches, execution enters `default` if it exists. Without `default`, no case body runs. The program must not silently treat an unknown zone as a valid fare. The provided function returns `-1` for an invalid zone, and `canTravel` rejects negative fares.

## Completed code output expected

```text
Fare Rs 10.00 balance Rs 90
Fare Rs 36.00 balance Rs 54
Denied (low balance) balance Rs 54
```

The first trip costs ₹10, leaving ₹90. The peak Outer fare is ₹30 + 20% = ₹36, leaving ₹54. The next ₹20 fare would leave ₹34, below the required ₹50, so it is denied.

## Alternative: array instead of switch

A fare array such as `constexpr long long FARE[] = {1000, 2000, 3000};` can be indexed by a validated zone value. Both array lookup and switch selection are O(1). The array occupies a fixed three-element storage area; a switch may compile to comparisons or a jump table. Adding Airport requires adding a new enum value and fare entry (and possibly changing validation). The switch requires adding a case. Array indexing is compact but must validate the index to avoid out-of-bounds access.

## Complexity

For `n` journeys, processing is O(n) time. The fare calculation for each journey is O(1). The supplied program uses O(1) extra space because it processes the fixed collection directly and does not allocate a second collection.
