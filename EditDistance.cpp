#include "EditDistance.h"
#include "Dynamic2DArray.h"
#include <string>
#include <algorithm>
#include <vector>     
#include <initializer_list> 

int editDistance(const std::string& str1, const std::string& str2) {
    const int len1 = str1.length();
    const int len2 = str2.length();
    
    Dynamic2DArray dp(len1 + 1, len2 + 1);

    for (int i = 0; i <= len1; i++) {
        dp.set_element(i, 0, i); 
    }
    
    for (int j = 0; j <= len2; j++) {
        dp.set_element(0, j, j);
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {

            const auto cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            const auto deletion     = dp.get_element(i - 1, j) + 1;
            const auto insertion    = dp.get_element(i, j - 1) + 1;
            const auto substitution = dp.get_element(i - 1, j - 1) + cost;

            dp.set_element(i, j, std::min({deletion, insertion, substitution}));
        }
    }

    return dp.get_element(len1, len2);
}
