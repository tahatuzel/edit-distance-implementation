#include "EditDistance.h"

#include <string>
#include <algorithm>
#include <vector>    
#include <initializer_list> 


int editDistance(const std::string& str1, const std::string& str2) {
    const auto len1 = str1.length();
    const auto len2 = str2.length();
    
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

    for (size_t i = 0; i <= len1; i++) {
        dp[i][0] = i; 
    }
    
    for (size_t j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {

            const auto cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            const auto deletion     = dp[i - 1][j] + 1;
            const auto insertion    = dp[i][j - 1] + 1;
            const auto substitution = dp[i - 1][j - 1] + cost;

            dp[i][j] = std::min({deletion, insertion, substitution});
        }
    }

    return dp[len1][len2];
}
