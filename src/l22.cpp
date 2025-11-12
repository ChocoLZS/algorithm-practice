#include <cstdio>
#include <memory>
#include <vector>
#include <string>

class SolutionNormalBacktrace {
public:
    void backtrace(int n, int left, int right, std::string& pattern ,std::vector<std::string>& res) {
        printf("%s %s\n",__func__ ,pattern.c_str());
        if (pattern.size() == n * 2) {
            res.push_back(pattern);
            // pattern.resize(pattern.size() - right);
            return;
        }
        if (left < n) {
            pattern.push_back('(');
            backtrace(n, left + 1, right, pattern, res);
            pattern.pop_back();
        }
        if (right < left) {
            pattern.push_back(')');
            backtrace(n, left, right + 1, pattern, res);
            pattern.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res{};
        std::string pattern = "";
        backtrace(n, 0, 0, pattern, res);
        return res;
    }
};

class Solution {
    std::shared_ptr<std::vector<std::string>> cache[100] = {nullptr};
public:
    std::shared_ptr<std::vector<std::string>> generate(int n) {
        if (cache[n] != nullptr) return cache[n];
        if (n == 0) {
            cache[0] = std::shared_ptr<std::vector<std::string>>(new std::vector<std::string>{""});
        } else {
            auto result = std::shared_ptr<std::vector<std::string>>(new std::vector<std::string>);
            for (int i = 0; i < n;i++) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const std::string& left: *lefts) {
                    for (const std::string& right: *rights) {
                        result->push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = result;
        }
        return cache[n];
    }

    std::vector<std::string> generateParenthesis(int n) {
        return *generate(n);
    }
};

int main() {
    auto res = SolutionNormalBacktrace().generateParenthesis(3);
    for (auto str : res) {
        printf("%s\n", str.c_str());
    }
}