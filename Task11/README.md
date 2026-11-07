# Task 11 – Recommend and Defend the Final Design

## Objective
Recommend a final design for the original three-zone metro system and defend the choices using the earlier implementation and numeric experiments.

## Files
- `final_design.md` – design recommendation, limitations and complexity analysis.
- `fare_config.txt` – example fare configuration.
- `config_reader.cpp` – optional alternative showing how fare values can be loaded at start-up.

## Run the configuration alternative (MSVC)
```powershell
cl /std:c++17 /W4 /EHsc config_reader.cpp
.\config_reader.exe
```

## Recommendation
Use integer paise (`long long`), `constexpr` policy values, `enum class` for zones, a central fare-calculation component and a `SmartCard` class with a private balance. Keep the minimum-balance rule inside the card's controlled operations.

The example configuration reader is an alternative concept for evaluating runtime fare changes. It is not a replacement for the main task implementations unless the design is deliberately changed.
