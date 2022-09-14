function minPathSum(grid: number[][]): number {
    let m = grid.length;
    let n = grid[0].length;
    if (m == 1 && n == 1) return grid[0][0];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (m == 0 && n == 0) {
                continue;
            }
            if (i == 0) {
                grid[i][j] += grid[i][j - 1];
            } else {
                if (j == 0) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += Math.min(grid[i][j - 1], grid[i - 1][j])
                }
            }
        }
    }
    return grid[m - 1][n - 1];
};