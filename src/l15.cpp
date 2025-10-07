#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
public:
    // 思路不对
    static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0) return std::vector<std::vector<int>>{};
        if (nums[nums.size()-1] < 0) return std::vector<std::vector<int>>{};
        int left = 0, right = nums.size() - 1;
        std::vector<std::vector<int>> res{};
        int float_index = -1; // will change later
        while (right - left >= 2) {
            int sum = nums[left] + nums[right];
            // 判0
            bool is_negative = sum < 0 ? true : false;

            // printf("left: %d, right: %d\n", nums[left], nums[right]);
            if (is_negative) { // 需要更多的正值
                float_index = right - 1; // 从右开始遍历
                while(float_index > left) {
                    if (sum + nums[float_index] == 0) {
                        // 命中break;
                        res.push_back(std::vector<int> { nums[left], nums[right], nums[float_index] });
                        break;
                    }
                    if (sum+nums[float_index] < 0) break; // 说明正值数量不够
                    float_index--;
                }
                // 负值太大了，向右走走，也许下次sum就是正值
                while (left < right -2) { // 如果相等跳过重复
                    if (nums[left] == nums[left+1]) {
                        left++;
                    } else {
                        break;
                    }
                }
                left++;
            } else {
                float_index = left + 1;
                // try to find float_index that meets sum 0;
                while(float_index < right) { // go right
                    if (sum+nums[float_index] == 0) {
                        // record
                        res.push_back(std::vector<int> { nums[left], nums[right], nums[float_index] });
                        break;
                    }
                    if (sum + nums[float_index] > 0) break;
                    float_index++;
                }

                while (left < right -2) { // 如果相等跳过重复
                    if (nums[right] == nums[right-1]) {
                        right--;
                    } else {
                        break;
                    }
                }
                right--;
            }

        }
        return res;
    }
};

int main() {
    std::vector<int> nums  = {-1,0,1,2,-1,-4};
    auto res = Solution::threeSum(nums);
    for (auto vec : res) {
        for (auto num: vec) {
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}