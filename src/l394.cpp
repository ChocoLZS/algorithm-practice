#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

class Solution {
public:
    bool is_ch(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    bool is_left(char ch) {
        return ch == '[';
    }
    bool is_right(char ch) {
        return ch == ']';
    }
    // 栈会将结果也存进栈，需要理用栈的特性
    std::string decodeString(std::string s) {
        std::string res;
        std::vector<std::string> stack;
        for (auto ch: s) {
            if (stack.empty() && is_ch(ch)) {
                res.push_back(ch);
                continue;
            }
            // handle
            stack.push_back(std::string(1, ch));
            if (stack.back() == "]") {
                stack.pop_back();
                std::string tmp_str;
                // pop until meets '['
                while (stack.back() != "[") {
                    stack.pop_back();
                }
                stack.pop_back();
                std::reverse(tmp_str.begin(), tmp_str.end());
                std::string digit_str;
                // handle number
                while (!stack.empty() && is_digit(stack.back())) {
                    digit_str.push_back(stack.back());
                    stack.pop_back();
                }
                std::reverse(digit_str.begin(), digit_str.end());
                int count = std::stoi(digit_str);
                std::string tmp_nested_str = tmp_str + nested_str;
                nested_str.clear();
                for (int i = 0; i < count; ++i) {
                    nested_str += tmp_nested_str;
                }
            }
            if (stack.empty()) {
                res.append(nested_str);
                nested_str.clear();
            }
        }
        return res;
    }
};

int main() {
    Solution().decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
}