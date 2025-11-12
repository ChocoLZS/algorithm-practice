#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max = 0;
        int min_buy = INT32_MAX;
        for (auto price : prices) {
            if (price < min_buy) min_buy = price;
            if (price >= min_buy) max = std::max(max, price - min_buy);
        }
        return max;
    }
};