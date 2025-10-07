#include "leetcode.hpp"

#include "math.h"

int main() {
    std::vector<u_int16_t> cost = {1, 100, 1,1,1,100,1,1,100,1};

    u_int16_t len = cost.size();

    u_int16_t i = 2;
    for (; i < len; i++) {
        cost[i] = std::min(cost[i - 1], cost[i -2]) + cost[i];
    }
    printf("%d", std::min(cost[i - 1], cost[i -2]));
    return 0;
}

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         u_int16_t i = 2;
//         u_int16_t len = cost.size();
//         for (; i < len; i++) {
//             cost[i] = std::min(cost[i - 1], cost[i - 2]) + cost[i];
//         }
//         return std::min(cost[i - 1], cost[i - 2]);
//     }
// };