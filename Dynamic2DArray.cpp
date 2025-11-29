#include "Dynamic2DArray.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>     // For std::to_string (replaces sstream)
#include <vector>     // Required for std::vector

// <sstream> and <cstddef> are no longer needed

using namespace std;

// The intToString helper function is no longer needed.
// We can use std::to_string() from the <string> header.

// --- Constructor ---
Dynamic2DArray::Dynamic2DArray(int R, int C) : rows(R), cols(C) {
    if (R <= 0 || C <= 0) {
        throw std::invalid_argument("Rows and columns must be positive.");
    }

    // C++11: std::vector handles all allocation.
    // We resize the outer vector to have 'R' rows. Each row is
    // a 'std::vector<int>' of size 'C', default-initialized to 0.
    try {
        data.resize(R, std::vector<int>(C));
    } catch (const std::bad_alloc& e) {
        // If allocation fails, we just report and re-throw.
        // No manual cleanup/rollback is needed, as std::vector handles it.
        std::cout << "-> Allocation failed: " << e.what() << "\n";
        throw; 
    }
    // All 'try/catch' logic for row-by-row allocation is gone.
}

// --- Destructor ---
Dynamic2DArray::~Dynamic2DArray() {
    // C++11: With std::vector, this is now empty!
    // The vector's own destructor handles all deallocation
    // automatically when the Dynamic2DArray object is destroyed.
    // All 'if (data != NULL)' and 'delete[]' loops are gone.
}

// --- Get Element ---
int Dynamic2DArray::get_element(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        // C++11: Use std::to_string instead of the custom intToString
        throw std::out_of_range("Index (" + std::to_string(r) + ", " + 
                                std::to_string(c) + ") is out of bounds.");
    }
    return data[r][c]; // vector::operator[] works just like the pointer
}

// --- Set Element ---
void Dynamic2DArray::set_element(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        // C++11: Use std::to_string
        throw std::out_of_range("Index (" + std::to_string(r) + ", " + 
                                std::to_string(c) + ") is out of bounds.");
    }
    data[r][c] = value;
}

// --- Print ---
void Dynamic2DArray::print(const std::string& str1, const std::string& str2) const {
    cout << "\n--- DP Table (" << rows << "x" << cols << ") ---\n";
    cout << setw(4) << " " << " |" << setw(6) << " " << "|";

    // C++11: Range-based for loop to iterate over the string
    for (char c : str2) {
        cout << setw(6) << c << "|";
    }
    cout << "\n" << string(8 + 7 * cols, '-') << "\n";

    // Outer loop remains index-based to print the row header (str1)
    for (int i = 0; i < rows; i++) {
        cout << setw(4) << (i == 0 ? " " : string(1, str1[i-1])) << " |";
        
        // C++11: Range-based for loop to iterate over the inner vector (the row)
        // This is more readable than the old C-style for loop.
        for (int val : data[i]) {
            cout << setw(6) << val << "|";
        }
        cout << "\n" << string(8 + 7 * cols, '-') << "\n";
    }
    cout << "--------------------------------\n";
}
