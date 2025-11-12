#include <numeric>
#include <vector>

class Solution {
public:
    // o(n) 算总和　/ 2  只要找到和为 total / 2 的组合就行
    // o(nlogn) 排序
    bool canPartition(std::vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; // odd
        sum = sum >> 1; // even
        // 在数组中，寻找是否有组合 和 == sum
        // 排序递增
        // 回溯 从大往小找
        // 二分查找
        // -----
        // 0-1 背包
        // dp的长度是背包容量
        // dp[sum] = dp[sum - num];
        std::vector<bool> bag(sum + 1, false);
        bag[0] = true;
        for (auto num : nums) {
            for (int i = sum; i>= num; i--) {
                bag[i] = bag[i] || bag[i - num];
            }
        }
        return bag.back();
    }
};