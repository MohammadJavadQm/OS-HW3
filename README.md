🖥️ Multi-threaded C Projects

This repository contains two multi-threaded C programs:

Sorting Program – Array sorting using threads
Sudoku Validator – Validates a Sudoku board using threads

📂 Project Structure
project-root/
│
├── sorting_program/
│   ├── main.c      # C code for multi-threaded sorting
│   └── main.exe    # Windows executable (optional)
│
├── sudoku_validator/
│   ├── main.c      # C code for Sudoku validation with threads
│   └── main.exe    # Windows executable (optional)
│
└── README.md       # Project documentation

🛠️ Prerequisites

C compiler with pthread support (e.g., gcc)
Operating System: Linux / Windows (with MinGW or WSL)

🔹 Part 1: Sorting Program
Program Description

Sorts an array using Bubble Sort with multi-threading
Splits the array into two halves, each sorted by a separate thread
Uses thread merge to combine the results
Displays the sorted array as output

Compile and Run
cd sorting_program
gcc -pthread main.c -o main
./main

Sample Output
Sorted array: 1 2 3 4 5 6 7 8 9 10

🔹 Part 2: Sudoku Validator
Program Description

Validates a 9x9 Sudoku board
Uses threads to check rows, columns, and 3x3 sub-grids
Outputs invalid if any errors are found

Compile and Run
cd sudoku_validator
gcc -pthread main.c -o main
./main

Sample Output
Sudoku board is valid

⚙️ Technical Notes

Uses pthread_mutex to protect the shared is_sudoku_valid variable
Sorting program implements Bubble Sort + Merge
Both programs demonstrate multi-threading in C

📄 License
This project is licensed under the MIT License. You are free to use and modify it.
📞 Contact

Email: mohammadjavad.m@gmail.com
GitHub: MohammadJavadQm
