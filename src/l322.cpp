#include <algorithm>
#include <vector>
#include <cstdint>

class Solution {
public:
    // for loop
    // dp[amount] = std::min(dp[amount - coin1],... dp[amount - coinN]) + 1;
    // dp[amount] = dp[amount - coin] + 1;
    // 
    int coinChange(std::vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        std::vector<int> dp(amount + 1, -1); // -1 
        dp[0] = 0;
        for (int i = 1; i <= amount;i++) {
            for (auto coin : coins) {
                if (coin > i) break;
                if (dp[i - coin] == -1) continue;
                if (dp[i] == -1) { // 未初始化
                    dp[i] = dp[i - coin] + 1;
                } else { // 有数据，做对比
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount];
    }
};