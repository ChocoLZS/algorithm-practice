#include <algorithm>
#include <vector>
class Solution {
public:
    // 从前往后找，每次都寻找范围内的最大值：增加搜寻范围
    int jump(std::vector<int>& nums) {
        if (nums.size() <= 1) return 0; 
        int i = 0;
        int tmp_max = 0;
        int count = 0;
        while (i < nums.size()) {
            int num = nums[i];
            if (num + i >= nums.size() - 1) break;
            tmp_max = num;
            for (int j = 1;j <= num; j++) { // 1, 1, 1, 1
                if (nums[i+j] >= tmp_max) { // 尽可能向前走
                    i = i+j;
                    tmp_max = nums[i+j];
                }
            }
            count++;
        }
        count++; // 最后一跳
        return count;
    }
};