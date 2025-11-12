class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prev_2 = 1;
        int prev_1 = 1;
        int ans = 0;
        for (int i = 2;i <= n;i++) {
            ans = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = ans;
        }
        return ans;

    }
};