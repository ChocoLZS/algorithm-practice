#include <string>
#include <vector>

class Solution {
public:

// 　bool dp[i][j] 以i开头j结尾的最长回文子串
// dp[i][j] = dp[i-1][j] dp[i][j-1] dp[i-1][j-1]
// 遍历方向，从i  = j 开始，分别左右遍历, i 减小，j 增大，如果没有回文条件，则提前终止并退出
// 如果遍历完全，则返回长度
// 同时要记录当前dp的index

// 中心扩展
//
    int expand(std::string &s, int left, int right) {
        if (left < 0 || right >= s.length() || left > right || s.at(left) != s.at(right)) return 0;
        while (left - 1 >= 0 && right + 1 <= s.length() - 1) {
            if (s.at(left - 1) != s.at(right + 1)) break;
            left--;
            right++; 
        }
        return right - left + 1;
    }
    std::string longestPalindrome(std::string s) {
        int max_len = 1;
        int max_start = 0;
        for (int i = 0;i < s.size()-1;i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            if (len1 > len2) {
                if (max_len < len1) {
                    max_len = len1;
                    max_start = i - max_len/2;
                }
            } else {
                if (max_len < len2) {
                    max_len = len2;
                    max_start = i - max_len/2 + 1;
                }
            }
        }
        return s.substr(max_start, max_len);
    }   
};