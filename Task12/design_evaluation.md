# Task 12 – Design Evaluation and Defence

## Decision: MODIFY the original design

The original object-oriented approach remains suitable, but its fare representation and policy responsibilities should be extended. A four-element fare table replaces repeated switch branches, a separate weekend rule is introduced, and a `MonthlyPass` class represents zone coverage.

## A. Impact analysis

| Original component | Required change |
|---|---|
| `Zone` enum class | Add `Airport` |
| Fare constants | Add Airport = 6000 paise and weekend discount = 10% |
| Fare selection | Support four zone values |
| Fare expression | Apply weekend discount instead of peak surcharge when weekend is true |
| `SmartCard` | Keep private balance and minimum-balance validation |
| New `MonthlyPass` | Store two covered zones and active status |
| Tests | Add Airport, weekend/peak interaction and pass coverage cases |

## B. Evaluate the original switch and SmartCard

A switch can support Airport by adding another case, so it is not inherently incorrect. However, each new zone requires editing the switch. A table indexed by the scoped enum makes the zone-to-fare mapping compact, provided the enum values remain contiguous and are range-checked.

The original SmartCard can still enforce the ₹50 remaining-balance invariant. It does not need to know why a fare is zero; a separate pass object decides whether the journey is covered.

## C. Adapted design and worked examples

The implementation uses integer paise and a four-entry `std::array`.

- Airport off-peak: ₹60.00.
- Airport peak: ₹60 × 1.20 = ₹72.00.
- Airport weekend: ₹60 × 0.90 = ₹54.00.
- If both weekend and peak flags are true, the weekend rule is applied and the peak surcharge is not added.
- A monthly pass covering Inner and Middle waives fares for journeys in those zones.

The weekend discount is checked before the peak surcharge, making the non-combination rule explicit.

## D. Evidence-based defence

The program demonstrates the new rules using worked examples. The fare lookup and pass coverage check are O(1). Card validation and deduction are O(1). Processing `n` journeys remains O(n). The fare table occupies O(z) space for `z` zones; the pass stores exactly two zones, O(1) space.

## Trade-offs and limitations

- A table is easier to extend with additional zones than a long switch, but requires careful enum-to-index validation.
- The prototype assumes a valid monthly pass is active for the simulated month. Real expiry dates, renewal, pass pricing and account binding are not implemented.
- The assignment does not specify how the monthly pass interacts with student/senior concessions, so no stacking policy is invented.
- The ₹50 minimum remaining balance is preserved even for a zero-fare pass journey. This is a conservative interpretation of the original journey rule.
- The weekend discount uses integer paise rounding. If future fares can produce fractions smaller than one paise, the authority must define the rounding policy.

## Complexity summary

| Operation | Complexity |
|---|---|
| Fare table lookup | O(1) |
| Weekend/peak calculation | O(1) |
| Monthly pass zone check | O(1) |
| SmartCard validation and deduction | O(1) |
| Process n journeys | O(n) |
| Fare table storage | O(z) |
| MonthlyPass storage | O(1) |

**Conclusion:** Modify rather than discard the original OOP design. The SmartCard invariant remains valuable, while the fare table and separate MonthlyPass make the revised system easier to extend and test.
