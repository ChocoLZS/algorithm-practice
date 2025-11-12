#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res(numRows, std::vector<int>{});
        res[0].push_back(1);
        for (int i = 1;i < numRows; i++) {
            res[i].push_back(1);
            for (int inner = 1; inner < i; inner++) {
                res[i].push_back(res[i-1][inner-1] + res[i-1][inner]);
            }
            res[i].push_back(1);
        }
        return res;

    }
};