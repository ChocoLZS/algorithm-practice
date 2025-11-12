#include <utility>
#include <vector>
// #include <range>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<std::pair<int, int>> stack; // 入栈元素比栈顶元素大，弹出并记录。
        std::vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size();i++) {
            int temp = temperatures[i];
            while (!stack.empty() && stack.back().first < temp) {
                auto [_, index] = stack.back();
                stack.pop_back();
                res[index] = i - index; 
            }
            stack.push_back({temp, i});
        }
        return res;
    }
};