#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:


// method 2 思路一致，但是少了数学思维
    static void rotate_wrong(std::vector<int>& nums, int k) {
        int tmp = nums[0];
        int swap_tmp = 0;
        if (k > nums.size()) {
            k = k % nums.size();
        }
        int total_cycle = k;
        int index = 0;
        while(total_cycle > 0) {
            // inner move
            do {
                printf("index: %d, tmp: %d\n", index, tmp);
                if (index + k >= nums.size()) {
                    index = (index + k) % nums.size();
                    swap_tmp = nums[index];
                    nums[index] = tmp;
                    tmp = swap_tmp;
                    if (nums.size() % k == 0 && index < nums.size() - 1) {
                        index++;
                        tmp = nums[index];
                    }
                    break;
                }

                // swap
                swap_tmp = nums[index + k];
                nums[index + k] = tmp;
                tmp = swap_tmp;
                
                index += k;

            } while (true); // 退出条件的问题
            total_cycle--;
        }
    }


    static void rotate_method2(std::vector<int>& nums, int k) {
        k = k % nums.size();
        int total_cycle = std::gcd(nums.size(), k); // totoal cycle 的问题
        for (int i = 0; i < total_cycle; i++) {
            int index = i;
            int tmp = nums[index];
            do {
                int next = index = (index + k) % nums.size();
                // swap
                std::swap(nums[next], tmp);
                
                index = next;

            } while (index != i);
        }
    }

    static void rotate(std::vector<int>& nums, int k) {
        std::vector<int> rotated_nums((int)nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            rotated_nums[(i+k) % nums.size()] = nums[i];
        }
        nums.assign(rotated_nums.begin(), rotated_nums.end());
    }

    static void reverse(std::vector<int>& nums, int start, int end) {
        int tmp = 0;
        while (start < end) {
            tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }

    // 方法三，逆转数组
    static void rotate_reverse(std::vector<int>& nums, int k) {
        k = nums.size() % k;
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main() {
    std::vector<int> nums{1,2};
    int k = 7;
    Solution::rotate(nums, k);
    for (auto num : nums) {
        printf(
            "%d ", num
        );
    }
}