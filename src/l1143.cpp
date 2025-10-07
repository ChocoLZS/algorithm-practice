#include "leetcode.hpp"
#include "math.h"

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
