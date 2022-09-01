function numTrees(n: number): number {
    let map = {};
    map[0] = 1;
    map[1] = 1;
    map[2] = 2;
    if (n < 3) {
        return map[n];
    }
    for (let i = 3; i <= n; i++) {
        map[i] = 0;
        for (let root = 1; root <= i; root++) {
            map[i] += map[root - 1] * map[i - root];
        }
    }
    return map[n];
};