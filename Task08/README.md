# Task 08 – Read and Print Data Safely

**Compiler:** Microsoft Visual C++ (MSVC), C++17  
**Compile direct input:** `cl /std:c++17 /W4 /EHsc safe_input_cin.cpp`  
**Compile getline alternative:** `cl /std:c++17 /W4 /EHsc safe_input_getline.cpp`

Run each executable. For `safe_input_cin.exe`, try entering `abc` when asked for an hour; it should report invalid input, clear the stream state, discard the bad line and ask again. Save screenshots showing recovery and a formatted report.
