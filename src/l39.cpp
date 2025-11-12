#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
    static void print_arr(std::vector<int>& arr) {
        for (auto num : arr) {
            printf("%d ",num);
        }
        printf("\n");
    }

    void backtrace(int remain, int min, std::vector<int>& candidates, std::vector<int>& arr, std::vector<std::vector<int>>& res) {
        if (remain < 0) return;
        if (remain == 0) {
            res.push_back(arr);
            return;
        }
        for (int i = candidates.size() - 1; i >= 0; i--) {
            int num = candidates[i];
            if (num > remain || num > min || remain - num < 0) continue;
            arr.push_back(num);
            backtrace(remain - num, num, candidates, arr, res);
            arr.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>>res;
        std::vector<int> arr;
        std::sort(candidates.begin(), candidates.end());
        backtrace(target, INT32_MAX, candidates, arr, res);
        return res;
    }
};

int main() {
    std::vector<int> candidates{
        2,3,6,7
    };
    auto res = Solution().combinationSum(candidates, 7);
    for (auto it : res) {
        Solution::print_arr(it);
    }
}