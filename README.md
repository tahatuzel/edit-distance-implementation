# Edit Distance Algorithm Comparator

This project is a C++ application that calculates the **Edit Distance (Levenshtein Distance)** between two strings. 

The main purpose of this application is to demonstrate the significant performance difference between a **Dynamic Programming** approach (optimized) and a raw **Recursive** approach (naive). It measures and compares the execution time of both algorithms in microseconds.

## 📂 File Structure

* **`main.cpp`**: The entry point of the application. Handles user input, measures execution time using `std::chrono`, and displays the comparison results.
* **`EditDistance.cpp / .h`**: Implementation of the algorithm using **Dynamic Programming** (Iterative approach).
* **`EditDistanceRecursive.cpp / .h`**: Implementation of the algorithm using **Recursion**.
* **`Dynamic2DArray.cpp / .h`**: A helper class for managing 2D arrays dynamically.

## 🚀 Features

* **Algorithm Comparison:** Runs both DP and Recursive algorithms on the same input.
* **Performance Metrics:** Displays execution time for both methods in microseconds.
* **Interactive Loop:** Allows testing multiple word pairs without restarting the program.
* **Cross-Platform Code:** Written in standard C++ (C++11), compilable on Windows, Linux, and macOS without IDE dependencies.
