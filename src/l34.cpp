#include <vector>

class Solution {
public:
    int binarySearch(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) >> 1;
        while (left <= right) {
            middle = (left + right) >> 1;
            int num = nums[middle];
            if (num > target) right = middle - 1;
            if (num < target) left = middle + 1;
            if (num == target) return middle;
        }
        return -1;
    }

    // O(n)
    std::vector<int> searchRange_poor(std::vector<int>& nums, int target) {
        int pos = binarySearch(nums, target);
        if (pos < 0) return std::vector<int>{-1, -1};
        int start = pos;
        int end = pos;
        while ( start >=0 && nums[start] == target) start--;
        start++;
        while (end <= nums.size() - 1 && nums[end] == target) end++;
        end--;
        return std::vector<int> { start, end};
    }

    // 二分寻找边界
    int binarySearchVariant(std::vector<int>& nums, int target, bool lower) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) >> 1;
        int ans = nums.size();
        while (left <= right) {
            middle = (left + right) >> 1;
            int num = nums[middle];
            if (num > target || (lower && num >= target)) { // lower == true, 如果num == target, 一定能保证ans是第一个元素
                right = middle - 1;
                ans = middle;
            } else {
                left = middle + 1;
            }
        }
        return ans;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = binarySearchVariant(nums, target, true);
        int right = binarySearchVariant(nums, target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) {
            return std::vector<int>{left, right};
        }
        return std::vector<int>{-1,-1};
    }
};