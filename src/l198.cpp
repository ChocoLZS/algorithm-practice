#include "leetcode.hpp"

int main() {
    std::vector<int> nums = {1,2,3,1};
    u_int16_t len = nums.size();
    if (len == 1)
        return nums[0];
    if (len == 2)
        return std::max(nums[0], nums[1]);
    if (len == 3)
        return std::max(nums[0] + nums[2], nums[1]);

    nums[2] += nums[0];
    u_int16_t i = 3;
    for (; i < len; i++){
        nums[i] = std::max(nums[i-2], nums[i-3]) + nums[i];
    }
    return std::max(nums[len-1], nums[len-2]);

    return 0;
}


// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         u_int16_t len = nums.size();
//         if (len == 1)
//             return nums[0];
//         if (len == 2)
//             return std::max(nums[0], nums[1]);
//         if (len == 3)
//             return std::max(nums[0] + nums[2], nums[1]);
//         nums[2] += nums[0];
//         u_int16_t i = 3;
//         for (; i < len; i++) {
//             nums[i] = std::max(nums[i - 2], nums[i - 3]) + nums[i];
//         }
//         return std::max(nums[len - 1], nums[len - 2]);
//     }
// };