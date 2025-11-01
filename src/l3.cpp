#include "leetcode.hpp"
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    static int lengthOfLongestSubstring_my(std::string s) {
        if (s.empty()) return 0;
        std::unordered_map<char, int>potential_chs{};
        int res = 1;
        int base = 0;
        // inital
        potential_chs.insert({s.at(0), 0});
        for (int index = 1; index <= s.length() - 1; ) {
            // try insert and check duplicate chars
            char new_ch = s.at(index);
            auto find = potential_chs.find(new_ch);
            if (find == potential_chs.end()) { // not found, new char, good
            } else {
                int next_index = find->second + 1;
                for (int j = base; j < next_index; j++) {
                    potential_chs.erase(s.at(j));
                }
                base = next_index;
            }
            potential_chs[new_ch] = index; // override
            index++; // try to increase window size
            res = std::max((int)potential_chs.size(), res);
        }
        return res;
    }
    // standard
    static int lengthOfLongestSubstring(std::string s) {
        if (s.size() <= 1) return s.length();
        int ch[258] = {0};
        int max_res = 1;
        int cur_res = 1;
        int str_begin = 1;
        int cur_index = 2;
        ch[s.at(0)] = 1; // 设置第一个字符的index为1 > 0
        while (cur_index <= s.size()) {
            char cur_ch = s.at(cur_index - 1);  // index - 1 才是真正在字符串中的坐标
            if (ch[cur_ch] > 0) {
                printf("%c is duplicated at %d\n", cur_ch, ch[cur_ch]);
                // set 0
                int new_str_begin = ch[cur_ch] + 1; // acbzb a = 1 b = 3, new_str_begin = 4 1 
                for (int i = str_begin; i < new_str_begin; i++) {
                    ch[s.at(i - 1)] = 0;
                }
                str_begin = new_str_begin;

                cur_res = cur_index - str_begin + 1;
                printf("%d, %d, %c\n", str_begin, cur_index, cur_ch);
            } else {
                cur_res++;
            }
            ch[cur_ch] = cur_index;
            printf(
                "set %c at %d\n", cur_ch, cur_index
            );
            cur_index++;
            max_res = std::max(max_res, cur_res);
        }
        return std::max(max_res, cur_res);
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");
    std::string example = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    printf(
        "res %d",
        Solution::lengthOfLongestSubstring(example)
    );
    return 0;
}