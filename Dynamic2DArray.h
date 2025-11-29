#ifndef DYNAMIC_2D_ARRAY_H
#define DYNAMIC_2D_ARRAY_H

#include <string>
#include <vector> // C++11: Include the vector header

class Dynamic2DArray {
private:
    // C++11: Replaced raw pointer with std::vector.
    // This vector will hold other vectors, creating the 2D structure.
    std::vector<std::vector<int>> data;
    
    int rows;
    int cols;

    // C++11: These are no longer needed!
    // By using std::vector, the default compiler-generated
    // copy constructor and assignment operator will work correctly.
    // This is known as the "Rule of Zero".
    //
    // Dynamic2DArray(const Dynamic2DArray&);
    // Dynamic2DArray& operator=(const Dynamic2DArray&);

public:
    // Constructor and Destructor remain the same
    Dynamic2DArray(int R, int C);
    ~Dynamic2DArray();

    // Member functions remain the same
    int get_element(int r, int c) const;
    void set_element(int r, int c, int value);
    void print(const std::string& str1, const std::string& str2) const;
};

#endif // DYNAMIC_2D_ARRAY_H
