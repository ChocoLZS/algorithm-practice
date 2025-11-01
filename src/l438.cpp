#include "leetcode.hpp"
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>

int ch_index(char ch) {
    return ch - 'a';
}

class Solution {
public:
    static std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.length() < p.length()) return std::vector<int>();
        int tmp_ch[26];
        std::fill(tmp_ch, tmp_ch+26, -1);
        for (auto ch : p) {
            if (tmp_ch[ch_index(ch)] < 0) {
                tmp_ch[ch_index(ch)] = 0;
            }
            tmp_ch[ch_index(ch)]++;
        }
        std::vector<int> res {};
        int left = 0;
        int right = 0;
        int max_length = p.size();
        int cur_length = 0;
        while (left < s.length() && right < s.length()) {
            if (right < left) {
                right = left;
            }
            while (right < s.length() && tmp_ch[ch_index(s.at(right))] > 0) { // 右指针前进，判断字符能否被消费，并且需要记录当前窗口长度
                tmp_ch[ch_index(s.at(right))]--;
                cur_length++;
                right++;
            }
            if (cur_length == max_length) {
                res.push_back(left);
            }

            if (tmp_ch[ch_index(s.at(left))] >= 0) {// 说明有这字符
                tmp_ch[ch_index(s.at(left))]++;
                cur_length--;
            } 
            left++;
        }
        if (cur_length == max_length) {
            res.push_back(left);
        }
        return res;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");
    std::string s = "bac", p = "abc";
    for (auto index: Solution::findAnagrams(s, p)) {
        printf("%d \n", index);
    } 
    return 0;
}