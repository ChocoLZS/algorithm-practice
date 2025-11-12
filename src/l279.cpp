#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>
class Solution {
public:

    bool isPerfectSquare(int n) {
        int square = static_cast<int>(std::sqrt(n));
        return square*square == n;
    }

    // 超时
    // o(n * n/2)
    int numSquares_overtime(int n) {
        if (n == 1) return 1;
        std::vector<int> dp(n+1, INT32_MAX);
        dp[1] = 1;
        for (int i = 2; i<=n;i++) {
            if (isPerfectSquare(i)) {
                dp[i] = 1;
            } else {
                int square = static_cast<int>(std::sqrt(i));
                for (int k = i-1; k>=square;k--) {
                    dp[i] = std::min(dp[i], dp[k] + dp[i-k]);
                }
            }
        }
        return dp[n];
    }

    // o(n* sqrt(n))
    int numSquares(int n) {
        std::vector<int> dp(n+1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i<=n;i++) {
            for (int j = 1; j*j <= i;i++) {
                dp[i] = std::min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }



};