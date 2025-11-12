#include <algorithm>
#include <vector>

class Solution {
public:
    bool canJump_tanxin(std::vector<int>& nums) {
        int step = 0;
        for (int i = 0; i < nums.size();i ++) {
            if (i > step) return false;
            step = std::max(step, i + nums[i]);
        }
        return true;
    }
    // reverse
    // 只要记录最后有地方能通过就行
    bool canJump(std::vector<int>& nums) {
        int pos = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0;i--) {
            if (i + nums[i] >= pos) {
                pos = i;
            }
        }
        return pos == 0;
    }
};