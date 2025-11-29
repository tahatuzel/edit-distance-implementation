#include "Dynamic2DArray.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string> 
#include <vector> 


using namespace std;


Dynamic2DArray::Dynamic2DArray(int R, int C) : rows(R), cols(C) {
    if (R <= 0 || C <= 0) {
        throw std::invalid_argument("Rows and columns must be positive.");
    }

    try {
        data.resize(R, std::vector<int>(C));
    } catch (const std::bad_alloc& e) {

        std::cout << "-> Allocation failed: " << e.what() << "\n";
        throw; 
    }
}

Dynamic2DArray::~Dynamic2DArray() {
}


int Dynamic2DArray::get_element(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {

        throw std::out_of_range("Index (" + std::to_string(r) + ", " + 
                                std::to_string(c) + ") is out of bounds.");
    }
    return data[r][c];
}


void Dynamic2DArray::set_element(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Index (" + std::to_string(r) + ", " + 
                                std::to_string(c) + ") is out of bounds.");
    }
    data[r][c] = value;
}

void Dynamic2DArray::print(const std::string& str1, const std::string& str2) const {
    cout << "\n--- DP Table (" << rows << "x" << cols << ") ---\n";
    cout << setw(4) << " " << " |" << setw(6) << " " << "|";

    for (char c : str2) {
        cout << setw(6) << c << "|";
    }
    cout << "\n" << string(8 + 7 * cols, '-') << "\n";

    for (int i = 0; i < rows; i++) {
        cout << setw(4) << (i == 0 ? " " : string(1, str1[i-1])) << " |";
        
        for (int val : data[i]) {
            cout << setw(6) << val << "|";
        }
        cout << "\n" << string(8 + 7 * cols, '-') << "\n";
    }
    cout << "--------------------------------\n";
}
