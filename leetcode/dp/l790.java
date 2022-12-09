package leetcode.dp;

public class l790 {
    public int numTilings(int n) {
        int MOD = (int)(1e9 + 7);
        int[][] dp = new int[n+1][4];
        dp[1][0] = dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][1];
            int cur = 0;
            for (int j = 0; j < 4; j++) {
                cur = (cur+dp[i-1][j]) % MOD;
            }
            dp[i][1] = cur;
            dp[i][2] = (dp[i-1][0] + dp[i-1][3]) % MOD;
            dp[i][3] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        }
        return dp[n][1];
    }
}
