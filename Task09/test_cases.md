# Task 09 – Test Cases and Expected Results

| Test | Input / condition | Expected fare | Expected decision |
|---|---|---:|---|
| Inner off-peak | Inner, 11:00 | ₹10.00 | Allow with sufficient balance |
| Middle off-peak | Middle, 12:00 | ₹20.00 | Allow with sufficient balance |
| Outer off-peak | Outer, 13:00 | ₹30.00 | Allow with sufficient balance |
| Inner peak | Inner, 08:00 | ₹12.00 | Allow with sufficient balance |
| Middle peak | Middle, 09:00 | ₹24.00 | Allow with sufficient balance |
| Outer peak | Outer, 18:00 | ₹36.00 | Allow with sufficient balance |
| 08:00 boundary | Inner, 08:00 | ₹12.00 | Peak |
| 10:00 boundary | Inner, 10:00 | ₹10.00 | Off-peak |
| 17:00 boundary | Inner, 17:00 | ₹12.00 | Peak |
| 20:00 boundary | Inner, 20:00 | ₹10.00 | Off-peak |
| Exact minimum | ₹80 balance, ₹30 fare | ₹30.00 | Allow; ₹50 remains |
| Below minimum | ₹79.99 balance, ₹30 fare | ₹30.00 | Deny; only ₹49.99 would remain |
| Unknown zone | Zone value outside 1–3 | Invalid | Deny |
| Negative recharge | Recharge = -₹5 | N/A | Reject; balance unchanged |
| Letters for hour | Input `nine` | N/A | Reject as invalid hour |

## Five journeys – manual calculation

1. Inner off-peak = ₹10.00
2. Middle peak = ₹24.00
3. Outer off-peak = ₹30.00
4. Inner peak = ₹12.00
5. Middle off-peak = ₹20.00

**Total = ₹10 + ₹24 + ₹30 + ₹12 + ₹20 = ₹96.00.**

The C++ program calculates these cases from the same fare functions and prints expected versus actual results. Record the output produced on your own machine after execution.
