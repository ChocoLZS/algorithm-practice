#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::unordered_set<char> left {
        '(', '{', '['
    };
    std::unordered_set<char> right {
        ')', '}', ']'
    };
    bool is_left(char ch) {
        return left.find(ch) != left.end();
    }
    bool is_right(char ch) {
        return right.find(ch) != right.end();
    }
    bool is_match(char ch_l, char ch_r) {
        if (ch_l == '(' && ch_r == ')') return true;
        if (ch_l == '[' && ch_r == ']') return true;
        if (ch_l == '{' && ch_r == '}') return true;
        return false;
    }
    bool isValid(std::string s) {
        std::vector<int> stack;
        bool result = true;
        for(auto ch : s) {
            if (is_left(ch)) {
                stack.push_back(ch);
            } else {
                if (stack.empty()) {
                    result = false;
                    break;
                }
                bool match = is_match(stack.back(),ch);
                if (!match) {
                    result = false;
                    break;
                }
                stack.pop_back();
            }
        }
        return result ? stack.empty() : result;
    }
};