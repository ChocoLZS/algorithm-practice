#include "leetcode.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    // 暴力
    int subarraySum_bruce(std::vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = nums[i];
            if (sum == k) res++;
            for (int j = i+1; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) res++;
            }
        }
        return res;
    }

    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> sum;
        int pre = 0;
        int res = 0;
        sum[0] = 1;
        for (int i = 0;i < nums.size(); i++) {
            pre += nums[i];
            auto find = sum.find(pre - k);
            if (find != sum.end()) {
                res += find->second;
            }
            sum[pre]++;
        }
        return res;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");

    return 0;
}