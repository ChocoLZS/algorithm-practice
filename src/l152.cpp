#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    // dp[i] 以 nums[i] 结尾的乘积最大值
    // 更新 i < j
    // dp[i][j] i..j 的乘积连续
    // dp[i][j] = dp[i][j-1] * num[j]
    // o(n^2)
    // -----
    // dp[i] 以nums[i]结尾的连续乘积最大值
    // dp[i] = dp[i-1] 
    // maxDp[i] 以 nums[i] 结尾的连续乘积最大值
    // minDp[i] 以 nums[i] 结尾的连续乘积最小值 // 有负数
    // 
    int maxProduct(std::vector<int>& nums) {
        int dp_min = nums[0];
        int dp_max = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp_max = dp_max;
            int tmp_min = dp_min;
            dp_max = std::max(
                nums[i],
                std::max(
                    tmp_max * nums[i],
                    tmp_min * nums[i]
                )
            );
            dp_min = std::min(
                nums[i],
                std::min(
                    tmp_max * nums[i],
                    tmp_min * nums[i]
                )
            );
            max = std::max(max, dp_max);
        }
        return max;
    }
};