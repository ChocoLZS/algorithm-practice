#include "leetcode.hpp"
#include <unordered_map>
#include <utility>
#include <vector>
// #include <algorithm>

class Solution {
public:
    // hash
    static std::vector<int> twoSum_hash(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> record{};
        record.emplace(nums[0], 0);
        std::vector<int> res{};
        for (int i = 1; i < nums.size(); i++) {
            if (record.find(target - nums[i]) != record.end()) {
                res.push_back(record.find(target - nums[i])->second);
                res.push_back(i);
                break;
            }
            record.emplace(nums[i], i);
        }
        return res;
    }
    // without hash
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res{};
        std::vector<std::pair<int, int>>record;
        for ( int i = 0;i < nums.size(); i++) {
            record.push_back({nums[i], i});
        }
        std::sort(record.begin(), record.end(), [](std::pair<int, int> a, std::pair<int, int>b){ return a.first < b.first;}); // 两边夹逼 k 一定处于中间值
        int left = 0, right = nums.size() - 1;
        while (left <= right - 1) {
            int sum = record[left].first + record[right].first;
            if (sum == target) {
                res.push_back(record[left].second);
                res.push_back(record[right].second);
                break;
            }
            if (sum > target) {
                right--;
            }
            if (sum < target) {
                left++;
            }
        }
        
        return res;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");

    return 0;
}