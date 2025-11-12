#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    // dp[i][j]  = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> dp(
            rows,
            std::vector<int>(cols, 0)
        );
        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                int result = 0;
                if (i == 0 && j == 0) {
                    result = 0;
                } else if (i == 0) {
                    result = dp[i][j - 1];
                } else if (j == 0) {
                    result = dp[i-1][j];
                } else {
                    result = std::min(dp[i-1][j], dp[i][j - 1]);
                }
                dp[i][j] = result + grid[i][j];
            }
        }
        return grid[rows-1][cols-1];
    }
};