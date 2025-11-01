#include <vector>
#include <string>

class Solution {
public:
    const std::vector<std::vector<char>> numpad {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };


    void backtrace(std::string& _str, int index, std::string& digits, std::vector<std::string>& res) {
        if (_str.size() == digits.size()) {
            res.push_back(_str);
            return;
        }
        char cur_ch = digits.at(index);
        for (auto ch: numpad[cur_ch - '2']) {
            _str.append(1, ch);
            backtrace(_str, index+1, digits, res);
            _str.erase(_str.length() - 1, 1);
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        std::string _str = "";
        backtrace(_str, 0, digits, res);
        return res;
    }
};