#include "leetcode.hpp"
#include "math.h"
#include <algorithm>
#include <vector>

#define indexOf(n) (n + 3) % 3

int main() {
    std::string text1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::string text2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    uint16_t dp[1002][1002] = {0};
    uint16_t max = 0;
    for (int index_text1 = 1; index_text1 <= text1.length(); index_text1++) {
        for (int index_text2 = 1; index_text2 <= text2.length(); index_text2++) {
            auto current_dp = &dp[index_text1][index_text2];
            if (text1.at(index_text1-1) == text2.at(index_text2-1)) {
                *current_dp = dp[index_text1-1][index_text2-1] + 1;
            } else {
                *current_dp = std::max(dp[index_text1-1][index_text2], dp[index_text1][index_text2-1]);
            }
            max = std::max(max, std::max(*current_dp, dp[index_text1 - 1][index_text2 - 1]));
        }
    }
    // return max;
    printf("%d", max);
    return 0;
}

class Solution {
public:
    // dp[i][j] 分别以 text1 i 结尾 text2 j 结尾的公共子序列
    // 如果 text1[i] == text2[j] 则 dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1])
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> dp(
            text1.size() + 1,
            std::vector<int>(
                text2.size() + 1,
                0
            )
        );
        int max = 0;
        for (int i = 1;i <= text1.size();i++) {
            for (int j = 1;j <= text2.size();j++) {
                int text1_index = i-1;
                int text2_index = j-1;
                dp[i][j] = std::max(text1.at(text1_index) == text2.at(text2_index) ? dp[i-1][j-1] + 1 : 0, 
                    std::max(dp[i-1][j], dp[i][j-1])
                );
                max = std::max(max, dp[i][j]);
            }
        }
        return max;
    }
};