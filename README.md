🖥️ Multi-threaded C Projects

This repository contains two multi-threaded C programs demonstrating the power of multi-threading in solving computational problems:

🔹 Sorting Program: A multi-threaded implementation of array sorting.
🔹 Sudoku Validator: A multi-threaded validator for a 9x9 Sudoku board.


📂 Project Structure
project-root/
│
├── sorting_program/
│   ├── main.c       # Source code for multi-threaded array sorting
│   └── main.exe     # Windows executable (optional)
│
├── sudoku_validator/
│   ├── main.c       # Source code for multi-threaded Sudoku validator
│   └── main.exe     # Windows executable (optional)
│
└── README.md        # Project documentation


🛠️ Prerequisites
To compile and run the programs, ensure you have:

A C compiler with pthread support (e.g., gcc).
Operating System:
Linux (recommended).
Windows (via MinGW or WSL).



Install gcc and pthread on Linux:
sudo apt update
sudo apt install gcc


🔹 Part 1: Sorting Program
📖 Description
This program implements Bubble Sort using multi-threading:

The input array is split into two halves, each sorted by a separate thread.
A merge step combines the sorted halves into a final sorted array.
The program prints the sorted array.

▶️ Compile and Run
cd sorting_program
gcc -pthread main.c -o main
./main

📝 Sample Output
Sorted array: 1 2 3 4 5 6 7 8 9 10


🔹 Part 2: Sudoku Validator
📖 Description
This program validates a 9x9 Sudoku board using multi-threading:

Separate threads check:
All rows.
All columns.
Each 3x3 sub-grid.


If any validation fails, the program reports the board as invalid.

▶️ Compile and Run
cd sudoku_validator
gcc -pthread main.c -o main
./main

📝 Sample Output
Sudoku board is valid


⚙️ Technical Details

Threading: Both programs use the pthreads library for multi-threading.
Synchronization: Uses pthread_mutex to manage shared variables (e.g., is_sudoku_valid in the Sudoku validator).
Sorting Algorithm: The sorting program combines Bubble Sort with a merge step for parallel processing.
Concepts: Demonstrates parallelism, thread synchronization, and efficient resource management in C.


🚀 Getting Started

Clone the repository:git clone https://github.com/MohammadJavadQm/multi-threaded-c-projects.git


Navigate to the desired program folder (sorting_program or sudoku_validator).
Compile and run using the commands provided above.


📄 License
This project is licensed under the MIT License.You are free to use, modify, and distribute this project.

📞 Contact

📧 Email: mohammadjavad.m@gmail.com
🌐 GitHub: MohammadJavadQm


🌟 Contributing
Contributions are welcome! Feel free to:

Open issues for bugs or suggestions.
Submit pull requests with improvements.


Built with 💻 and ☕ by MohammadJavadQm
