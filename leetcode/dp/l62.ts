function uniquePaths(m: number, n: number): number {
    let dp = Array.from(new Array(m + 1), () => new Array(n + 1).fill(0));
    dp[0][1] = 1;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
};