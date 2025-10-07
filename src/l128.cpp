#include "leetcode.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

class Solution {
public:
    // O(NlogN)
    int longestConsecutive_N_Log_N(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // 先排序
        std::sort(nums.begin(), nums.end());
        // 再统计
        int max_sequence = 0;
        int cur_sequence = 1;
        for (int i = 1; i <= nums.size() - 1; i++) { // look back
            if (nums[i] - nums[i-1] == 1) {
                cur_sequence++;
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                max_sequence = std::max(cur_sequence, max_sequence);
                cur_sequence = 1;
            }
        }
        return std::max(cur_sequence, max_sequence);
    }

    // 寻找当前节点是否为可能存在子序列的开始节点
    // 这样就只会尝试遍历所有的子序列 以及 每个节点
    // n + n
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set {nums.begin(), nums.end()};
        int sequence = 0;
        for (auto num : num_set) {
            if (num_set.count(num - 1) != 0) {
                continue;
            }
            // 以num为开头的节点
            // num 肯定在num_set中
            auto next = num + 1;
            while (num_set.count(next) > 0) next++;
            // next - 1 为最终值
            sequence = std::max(sequence, next - num);
        }
        return sequence;
    }
};
