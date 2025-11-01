#include "leetcode.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>

class Solution {
public:
    static int maxSubArray_normal(std::vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for (int i = 1; i <= nums.size() - 1;i++) {
            int cur_num = nums[i];
            // cur_sum 是序列子数组的和，cur_sum < 0, cur_num >= 0 那么有问题 // 更新
            cur_sum += cur_num;
            if (cur_sum < cur_num) {
                cur_sum = cur_num;
            }
            max_sum = std::max(cur_sum, max_sum);
        }
        return max_sum;
    }
    static int maxSubArray_dp(std::vector<int>& nums) {
        int max_sum = nums[0];
        int pre = nums[0];
        for (int i = 1; i <= nums.size() - 1;i++) {
            pre = std::max(pre + nums[i], nums[i]);
            max_sum = std::max(max_sum, pre);
        }
        return max_sum;
    }
    // 分治

    struct Status {
        // iSum 整段区间的和
        int lSum, rSum, mSum, iSum;
    };
    Status get(std::vector<int>& nums, int left, int right) {
        if (left == right) return Status{nums[left], nums[left], nums[left], nums[left]};
        int m = (left + right) / 2;
        Status left_part = get(nums, left, m);
        Status right_part = get(nums, m+1, right);
        // merge logic
        int lSum = std::max(left_part.lSum, left_part.iSum + right_part.lSum);
        int rSum = std::max(right_part.rSum, right_part.iSum + left_part.rSum);
        int iSum = left_part.iSum + right_part.iSum;
        int mSum = std::max(std::max(left_part.mSum, right_part.mSum), left_part.rSum + right_part.lSum);
        return Status{lSum, rSum, mSum, iSum};
    }
    int maxSubArray_sub(std::vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");
    std::vector<int> nums{5,4,-1,7,8};
    printf("%d", Solution::maxSubArray(nums));
    return 0;
}