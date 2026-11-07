# Task 08 – Safe Input and Formatted Output

## `cin` extraction and recovery

`if (std::cin >> value)` checks whether extraction succeeded. If the user types letters where an integer is expected, the stream enters a failure state. Further extraction will fail until the program calls:

1. `std::cin.clear()` to reset the failure flags.
2. `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n')` to discard the rest of the invalid input line.

The sample helper repeats the prompt until a whole number is entered. It separately handles end-of-file.

## Formatting the report

- `std::setw(n)` sets the width for the next formatted field.
- `std::setfill('0')` changes the fill character used by width formatting.
- `std::fixed` selects fixed-point floating output.
- `std::setprecision(2)` prints two digits after the decimal point.
- For exact fare computation, the program keeps the amount in integer paise. The conversion to rupees as `double` is used only for display.

## Alternative: getline and stoi

The alternative reads one complete line with `std::getline`, then converts using `std::stoi` inside `try/catch`. It also checks that no extra non-whitespace characters remain after the number.

For a line of length L, reading and validating the line takes O(L) time; parsing is O(L) in the worst case. The input string uses O(L) buffer space. Direct `cin >> int` is O(L) in the number of characters consumed and normally uses constant auxiliary storage for the numeric value. Both approaches can recover from invalid input. `cin` recovery requires clearing the stream and discarding the bad line; `getline` naturally consumes the whole line, and `stoi` reports malformed or out-of-range input through exceptions.

## Evidence to collect

Run `safe_input_cin.exe` and enter `abc` at the hour prompt, then enter a valid hour and zone. Save a screenshot showing the error message, retry, and final report. Also run the `getline` version with invalid input and record the result. Do not claim these executions until you have run them on your computer.
