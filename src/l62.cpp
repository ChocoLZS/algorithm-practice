#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(
            m + 1,
            std::vector<int>(n+1, 0)
        );
        dp[1][1] = 1;
        for (int row = 1; row <= m;row++) {
            for (int col = 1; col <= n;col++) {
                if (row == 1 && col == 1) continue;
                dp[row][col] = dp[row - 1][col] + dp[row][col-1];
            }
        }
        return dp[m][n];
    }
};