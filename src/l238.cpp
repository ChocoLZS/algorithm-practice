#include <vector>

class Solution {
public:
// O(n^2) 二层循环
// O(n)
    // 存储对应元素左边与右边的乘积，可以理解为dp
    std::vector<int> productExceptSelf_basic(std::vector<int>& nums) {
        std::vector<int> L(nums.size(), 1);
        std::vector<int> R(nums.size(), 1);
        // iterator L
        for (int i = 1; i < nums.size(); i++) {
            L[i] = L[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0 ; i--) {
            R[i] = R[i + 1] * nums[i + 1];
        }
        std::vector<int> ans(nums.size(), 0);
        for (int i =0;i < nums.size();i++) {
            ans[i] = L[i] * R[i];
        }
        return ans;

    }

    // 空间 O(1)
    // 利用nums和ans
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);
        // iterator L
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int R_tmp = 1;
        for (int i = nums.size() - 1; i >= 0 ; i--) {
            ans[i] = R_tmp * ans[i];
            R_tmp *= nums[i];
        }
        return ans;
    }
};