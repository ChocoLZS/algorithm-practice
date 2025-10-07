#include "leetcode.hpp"
#include <map>

int main() {
    std::vector<int> nums = {2,2,3,3,3,4};
    std::vector<std::pair<int, int>> cache = {};
    std::map<int, int> index_map = {};

    for (int i = 0;i < nums.size(); i ++) {
        int num = nums[i];
        if (index_map.find(num) != index_map.end()) {
            int index = index_map[num];
            std::pair<int ,int>& pair = cache[index];
            pair.second = pair.second + num;
        } else {
            index_map.insert(std::make_pair(num, cache.size()));
            cache.push_back(std::make_pair(num, num));
        }
    }
    std::sort(cache.begin(), cache.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    int len = cache.size();
    if (len == 1)
        return cache[0].second;
    int i = 1;
    for (; i < len;i++) {
        int max = 0;
        for (auto offset : {1,2,3}) {
            int left = i - offset;
            if (left >= 0 && (cache[left].first != cache[i].first - 1)) {
                max = std::max(max, cache[left].second);
            }
        }
        cache[i].second += max;
    }
    return std::max(cache[i-1].second, cache[i-2].second);
    

    return 0;
}