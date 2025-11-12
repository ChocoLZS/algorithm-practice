#include <cstdio>
#include <vector>

class Solution {
public:
    // 普通二分
    int binarySearch(std::vector<int>& nums, int _left, int _right, int target) {
        if (_left > _right) return -1;
        int left = _left;
        int right = _right;
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

    // 变种二分
    // 返回较大的坐标
    int binarySearchK(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) >> 1;
        while (left < right) {
            middle = (left + right) >> 1;
            int num = nums[middle];
            if (num >= nums[left]) { // 较大
                left = middle + 1;
                if (middle + 1 < nums.size() && num > nums[middle + 1]) return middle;
            }
            if (num < nums[right]) { // 较小
                right = middle - 1;
                if (middle - 1 >= 0 && num < nums[middle - 1]) return middle - 1;
            }
        }
        return middle; // 返回最大值坐标。说明排序后还是增序
    }

    int search_my(std::vector<int>& nums, int target) {
        int pos_k = binarySearchK(nums);
        int left_pos = binarySearch(nums, 0, pos_k, target);
        int right_pos = binarySearch(nums, pos_k + 1, nums.size() - 1, target);
        return left_pos >= 0 ? left_pos : right_pos;
    }

    // 但是实际上可以一个二分就解决问题
    // target肯定在一个有序的段落里
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (left > right) return -1;
        int middle = (left + right) >> 1;
        while (left <= right) {
            middle = (left + right) >> 1;
            int num = nums[middle];
            if (num == target) return middle;
            // 判断哪边有序
            if (nums[0] <= num) { // middle 在k左侧
                if (nums[0] <= target && target < num) { // 左侧有序
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                if (nums[0] < target && target <= nums.back()) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> nums = {3,1};
    int target = 0;
    auto res = Solution().search(nums, target);
    printf("%d", res);
}