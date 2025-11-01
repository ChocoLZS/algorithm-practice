#include <vector>

class Solution {
public:
    void backtrace(std::vector<int>& state, std::vector<int>& nums, std::vector<bool>& selected, std::vector<std::vector<int>>& res, int index) {
        if (state.size() == nums.size() - 1) {
            return;
        }
        for (int i = index;i < nums.size();i++) {
            if (!selected[i]) {
                selected[i] = true;
                state.push_back(nums[i]);
                res.push_back(state);
                backtrace(state, nums, selected, res, i);
                state.pop_back();
                selected[i] = false;
            }
        }

    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> state{};
        std::vector<std::vector<int>> res;
        std::vector<bool> selected(nums.size(), false);
        res.push_back(state);
        res.push_back(nums);
        backtrace(state, nums, selected, res, 0);
        return res;
    }
};