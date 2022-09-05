function numIslands(grid: string[][]): number {
    let res = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === "1") {
                infect(grid, i, j);
                res++;
            }
        }
    }
    return res;
};

function infect(grid: string[][], row: number, col: number) {
    if (row >= 0 && col >= 0 && row < grid.length && col < grid[0].length) {
        if (grid[row][col] === "1") {
            console.log(grid);
            grid[row][col] = "0";
            infect(grid, row - 1, col);
            infect(grid, row, col - 1);
            infect(grid, row + 1, col);
            infect(grid, row, col + 1);
        }
    }
}