#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // bad solution nlogn 排序，时间复杂度增加
    std::vector<std::vector<int>> merge_sort(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>a, std::vector<int>b){return a[0] < b[0];});
        std::vector<std::vector<int>> res;
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        int index = 1;
        while (index < intervals.size()) {
            std::vector<int> cur = intervals[index];
            if (cur_end >= cur[0]) {
                if (cur_end >= cur[1])
                    cur_end = cur[1];
            } else {
                res.push_back({cur_start, cur_end});
                cur_start = cur[0];
                cur_end = cur[1];
            }
            index++;
        }
        res.push_back({cur_start, cur_end});
        return res;
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>&a, const std::vector<int>b){return a[0] < b[0];});
        std::vector<std::vector<int>> res;
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        int index = 1;
        while (index < intervals.size()) {
            std::vector<int> cur = intervals[index];
            if (cur_end >= cur[0]) {
                if (cur_end >= cur[1])
                    cur_end = cur[1];
            } else {
                res.push_back({cur_start, cur_end});
                cur_start = cur[0];
                cur_end = cur[1];
            }
            index++;
        }
        res.push_back({cur_start, cur_end});
        return res;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");

    return 0;
}