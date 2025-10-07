#include <vector>

class Solution {
public:
    void swap(std::vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void moveZeroes_N2(std::vector<int>& nums) { // 很慢 n^2
        int right = 0; // 索引节点，尝试寻找0
        int right_end = nums.size()-1; // 末尾非0
        // 回溯end_flag
        while(right_end >= 0 && nums[right_end] == 0) right_end--;
        // 冒泡交换
        right = right_end - 1;
        while (right >= 0) {
            if (nums[right] == 0) {
                // 冒泡交换
                for (int i = right; i <= right_end - 1; i++) {
                    swap(nums, i, i+1);
                }
                // 前进
                right_end = right_end - 1;
            }

            right--;
        }
    }
    void moveZeroes(std::vector<int>& nums) {
        // 直接向前遍历就好
        // left 指向第一个0元素
        int left_first = 0;
        while (left_first < nums.size() && nums[left_first] != 0 ) left_first++;
        // left_first 指向了第一个0元素
        int after = left_first + 1;
        while (after < nums.size()) {
            if (nums[after] != 0) {
                swap(nums, left_first, after);
                left_first = left_first + 1;
            }
            after++;
        }
    }
};