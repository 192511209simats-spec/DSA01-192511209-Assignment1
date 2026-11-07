# Task 11 – Final Design Recommendation

## Recommended design

Retain the object-oriented design and improve the separation of responsibilities:

- `Zone` (`enum class`) represents the original three zones.
- A single fare table stores base fares in integer paise.
- `FareCalculator` determines the fare and applies the peak surcharge.
- `SmartCard` owns a private `long long balancePaise` and exposes validated recharge, `canTravel` and `deduct` operations.
- `Journey` represents the zone and travel time for one journey.
- Named constants define the 20% peak surcharge and ₹50 minimum remaining balance.

## Why these choices?

1. **Exact money:** integer paise avoids binary floating-point rounding in fare calculations.
2. **Range:** `long long` can hold the network-scale total in the Task 10 experiment; a typical signed `int` cannot hold 5,355,000,000 paise.
3. **Centralised policy:** one fare table and named constants reduce duplicated values.
4. **Encapsulation:** private card balance prevents unrelated code from setting it negative or bypassing the minimum-balance rule.
5. **Maintainability:** fare policy and card-balance policy are separate, so a fare revision does not require rewriting card validation.

## Fare revision procedure

For the original three-zone design, update the central fare table and re-run all normal, peak-boundary and balance-boundary tests. If policy values are compiled as `constexpr`, rebuild and redeploy the program after a change.

## Whole-network suitability

The fare calculation and balance validation each take O(1) time per journey. Processing `n` journeys takes O(n) time. The card stores a constant number of values, so memory per card is O(1). A network total should use `long long` rather than a typical 32-bit `int`.

## Limitations and assumptions

- Student and senior concession rates and their order of application are not specified in the assignment. They must be supplied by the metro authority before implementation.
- The original fare table is compiled into the program; runtime changes require a rebuild.
- The sample model does not cover refunds, journey transfers, concurrency, payment failures or audit persistence.
- The Task 10 traffic distribution is illustrative, not real operational data.

## Alternative: configuration file at start-up

The fare values could be loaded from a text configuration file when the gate starts. Reading `z` zone fares takes O(z) time and O(z) storage. For a small fixed number of zones this overhead is negligible, while fare revisions can be deployed by updating a validated configuration file rather than recompiling the executable. However, configuration parsing introduces file errors, malformed values and the need for validation/versioning. A compiled `constexpr` table is simpler and safer for a small fixed policy; a configuration file is more flexible when fares change frequently.

## Complexity comparison

| Operation | Complexity |
|---|---|
| Fare calculation | O(1) |
| Balance check and deduction | O(1) |
| Process n journeys | O(n) |
| Load z fares at start-up | O(z) time, O(z) storage |
| Memory per SmartCard | O(1) |

**Final decision:** retain the OOP design, use integer paise and centralise fare rules. Add runtime configuration only if operational requirements justify the added validation and deployment complexity.
