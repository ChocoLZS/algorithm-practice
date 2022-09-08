function coinChange(coins, amount) {
    let dp = new Array(amount + 1).fill(amount + 1);
    dp[0] = 0;
    for (let target = 1; target <= amount; target++) {
        for (let coin of coins) {
            if (target - coin < 0) continue;
            dp[target] = Math.min(dp[target], dp[target - coin] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
};