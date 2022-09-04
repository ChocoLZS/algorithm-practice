function combine(n: number, k: number): number[][] {
    let arr = new Array<Array<number>>();
    for (let i = 1; i <= n; i++) {
        helper(i, n, k, [i], arr);
    }
    return arr;
};

function helper(startNum: number, n: number, k: number, cur: number[], arr: number[][]) {
    if (n - startNum + 1 < k) return;
    if (k == 1) {
        arr.push([...cur]);
        return;
    }
    for (let i = startNum + 1; i <= n; i++) {
        cur.push(i)
        helper(i, n, k - 1, cur, arr);
        cur.pop();
    }
}

combine(4, 2)
