#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) >> 1;
        while (left <= right) {
            middle = (left + right) >> 1;
            if (nums[middle] == target) return middle;
            if (nums[middle] < target) left = middle + 1;
            if (nums[middle] > target) right = middle - 1;
        }
        return nums[middle] < target ? middle + 1 : middle;
    }
};