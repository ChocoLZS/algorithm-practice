/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var constructArray = function (n, k) {
    let ans = [];
    let index = 0;
    for (let i = 1; i <= n - k; i++) {
        ans.push(i);
        index++;
    }
    let bias = 0;
    while (index < n) {
        ans.push(n - bias);
        index++;
        ans.push(n - k + bias + 1);
        index++;
    }
    if (index > n) {
        ans = ans.slice(0, ans.length - 1);
    }
    return ans;
};
