#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    // time: o(n) space: o(1)
    int majorityElement(std::vector<int>& nums) {
        // o(1) 可能需要对nums进行修改
        // 摩尔投票，维护当前候选与counts
        // num不同则相互抵消，最后留下的一定是数量最多的num
        int candidates = 0;
        int counts = 0;
        for (auto num : nums) {
            if (counts == 0) {
                candidates = num;
            }
            if (num != candidates) {
                counts--;
            } else {
                counts++;
            }
        }
        return candidates;
    }

    // time: o(n) space: o(n)
    int majorityElement_normal(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        std::pair<int, int> maxs = {0, 0};
        for (auto num: nums) {
            auto it = counts.find(num);
            int count = 0;
            if (it == counts.end()) {
                count = 1;
                counts.emplace(num, count);
            } else {
                count = it->second + 1;
                it->second = count;
            }
            if (count > maxs.second) {
                maxs.first = num;
                maxs.second = count;
            }
            
        }
        return maxs.first;
    }
};