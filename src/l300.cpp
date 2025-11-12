#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
    // 后面的结果依赖前面的结果
    // i...j 的最长长度， 9,10,11,12,1,2,3,4,5,6,7,8,9
    // 0...j 的最长长度
    // dp[i][j] i <= j dp[i][j] 存储当前递增子序列的最大值和连续序列长度
    // i > j 时，dp[i][j] = 0;
    // dp[i][j] = dp[i-1][j] dp[i] > dp[i-1],  dp[i][j-1]
    int lengthOfLIS_poor(std::vector<int>& nums) {
        int max = 1;
        std::vector<std::vector<std::pair<int, int>>> dp(
            nums.size(),
            std::vector<std::pair<int, int>>(
                nums.size(),
                {0, 0}
            )
        );
        for (int i = 0;i < nums.size();i++) dp[i][i] = {nums[i], 1};
        for (int j = 1; j < nums.size(); j++) {
            for (int i = 0; i < j;i++) {
                dp[i][j] = 
            }
        }
        return max;
    }

    // dp[i] = 以nums[i] 结尾的最长递增子序列的长度
    // dp[i] = max(dp[j] + 1) // 遍历所有 j < i 且nums[j] < nums[i]
    // o(n^2)
    int lengthOfLIS_on2(std::vector<int>& nums) {
        int max = 0;
        std::vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i;j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max = std::max(max, dp[i]);
        }
        return max;
    }


    // 寻找第一个 >= target 的位置，如果 tail比所有值都大，返回-1
    int binarySearchVariant(std::vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (target > nums.back()) return -1;
        int left = 0, right = nums.size() - 1;
        int middle = (left + right) >> 1;
        while (left <= right) {
            middle = (left + right) >> 1;
            int num = nums[middle];
            if (target > num) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return left;
    }
    // o(nlogn)
    // 上述循环中，每次都要从头遍历数字，然后对比更新。目的是为了寻找：1. 比当前数字小的数，2. 找到最长的子序列
    // 需要维护一个数据结构，找到比nums[i]小的数，而且子序列长度最长的。
    // 新增一个数组 tail, tail[len] 代表长度为len的递增子序列中，末尾元素的相对最小值
    // tail 数组一定是递增的
    // 遍历 nums[i]
    // 当 nums[i] 比 tail中所有都大时，添加末尾
    // 否则 找到第一个 >= nums[i] 的位置，替换
    // 最后 tails.size() 为递增子序列长度
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> tails;
        for (auto num : nums) {
            auto index = binarySearchVariant(tails, num);
            if (index == -1) tails.push_back(num);
            else tails[index] = num;
        }
        return tails.size();
    }
};