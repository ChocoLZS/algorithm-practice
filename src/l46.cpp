#include <unordered_set>
#include <vector>

class Solution {
public:
    void backtrace(std::vector<int>& state, 
        const std::vector<int>& nums,
        std::vector<bool>& selected,
        std::vector<std::vector<int>>& res) {
            if (state.size() == nums.size()) {
                res.push_back(state);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                int choice = nums[i];
                if (!selected[i]) {
                    state.push_back(choice);
                    selected[i] = true;
                    backtrace(state, nums, selected, res);
                    selected[i] = false;
                    state.pop_back();
                }
            }
        } 
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>>res;
        std::vector<int> state; // 当前所选的数组
        std::vector<bool> selected(nums.size(), false);
        backtrace(state, nums, selected, res);
        return res;
    }
};