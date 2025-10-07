#include "leetcode.hpp"
#include <math.h>

int main() {
    std::string word1 = "leetcode";
    std::string word2 = "etco";
    std::vector<std::vector<uint>> dp(word1.size() + 1, std::vector<uint>(word2.size() + 1));
    for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for(int j = 1; j <= word2.size(); j++) {
            if (word1.at(i-1) == word2.at(j-1)) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = std::min(std::min(dp[i-1][j] + 1, dp[i][j-1]+1), dp[i-1][j-1]+2);
            }
        }
    }
    printf("result is %u", dp[word1.size()][word2.size()]);
    return 0;
}