# Task 06 – Fare computation pseudocode

```text
ALGORITHM CalculateFare(zone, isPeak)
    IF zone = INNER THEN
        baseFare ← 1000
    ELSE IF zone = MIDDLE THEN
        baseFare ← 2000
    ELSE IF zone = OUTER THEN
        baseFare ← 3000
    ELSE
        RETURN INVALID
    END IF

    IF isPeak = TRUE THEN
        surcharge ← baseFare × 20 / 100
        baseFare ← baseFare + surcharge
    END IF

    RETURN baseFare
END ALGORITHM

ALGORITHM ProcessJourneys(journeys, balance)
    FOR EACH journey IN journeys
        fare ← CalculateFare(journey.zone, journey.isPeak)
        IF fare = INVALID THEN
            CONTINUE
        END IF

        IF balance - fare >= 5000 THEN
            balance ← balance - fare
            DISPLAY accepted journey and balance
        ELSE
            DISPLAY insufficient balance
        END IF
    END FOR
END ALGORITHM
```

The pseudocode is deliberately language-neutral. Map the decisions to `if/else`, zone selection to `switch`, and the known trip collection to a range-based `for`.
