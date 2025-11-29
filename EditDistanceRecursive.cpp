#include "EditDistanceRecursive.h"

#include <string>
#include <algorithm>
#include <vector>
#include <initializer_list> 

int edit_distance_recursive(std::string str1, std::string str2) {
    const auto m = str1.length();
    const auto n = str2.length();

    if (m == 0) {
        return n;
    }

    if (n == 0) {
        return m;
    }

    if (str1[m - 1] == str2[n - 1]) {
        return edit_distance_recursive(str1.substr(0, m - 1), str2.substr(0, n - 1));
    }

    const auto insert_op  = edit_distance_recursive(str1, str2.substr(0, n - 1));
    const auto remove_op  = edit_distance_recursive(str1.substr(0, m - 1), str2);
    const auto replace_op = edit_distance_recursive(str1.substr(0, m - 1), str2.substr(0, n - 1));

    return 1 + std::min({insert_op, remove_op, replace_op});
}
