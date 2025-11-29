#include "EditDistanceRecursive.h"
#include <string>
#include <algorithm>
#include <vector>
#include <initializer_list> 


int edit_distance_engine(const std::string& str1, const std::string& str2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (str1[m - 1] == str2[n - 1]) {
        return edit_distance_engine(str1, str2, m - 1, n - 1);
    }

    return 1 + std::min({
        edit_distance_engine(str1, str2, m, n - 1),    // Insert
        edit_distance_engine(str1, str2, m - 1, n),    // Remove
        edit_distance_engine(str1, str2, m - 1, n - 1) // Replace
    });
}


int edit_distance_recursive(std::string str1, std::string str2) {
    int m = str1.length();
    int n = str2.length();

    return edit_distance_engine(str1, str2, m, n);
}
