#ifndef DYNAMIC_2D_ARRAY_H
#define DYNAMIC_2D_ARRAY_H

#include <string>
#include <vector>

class Dynamic2DArray {
private:
    std::vector<std::vector<int>> data;
    
    int rows;
    int cols;


public:
    Dynamic2DArray(int R, int C);
    ~Dynamic2DArray();

    int get_element(int r, int c) const;
    void set_element(int r, int c, int value);
    void print(const std::string& str1, const std::string& str2) const;
};

#endif

