function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    obstacleGrid[0][0] = 1;
    let m = obstacleGrid.length;
    let n = obstacleGrid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = Infinity;
                continue;
            }
            if (i == 0) {
                let res1 = validGrid(obstacleGrid, i - 1, j);
                if (res1 == Infinity) {
                    obstacleGrid[i][j] = Infinity;
                } else {
                    obstacleGrid[i][j] = res1 + obstacleGrid[i][j];
                }
            } else {
                let res1 = validGrid(obstacleGrid, i - 1, j);
                let res2 = validGrid(obstacleGrid, i, j - 1);
                if (res1 == Infinity && res2 == Infinity) {
                    obstacleGrid[i][j] = Infinity;
                } else {
                    obstacleGrid[i][j] =
                        res1 == Infinity ? 0 : res1
                            + res2 == Infinity ? 0 : res2
                }
            }
        }
    }
    return obstacleGrid[m - 1][n - 1];
};

function validGrid(obstacleGrid, x, y) {
    if (x < 0 || y < 0 || x >= obstacleGrid.length || y >= obstacleGrid[0].length) return 0;
    if (obstacleGrid[x][y] == Infinity) return Infinity;
    return obstacleGrid[x][y];
}