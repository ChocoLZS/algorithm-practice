package leetcode.bfs;

public class l200 {
    static int res = 0;
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1') {
                    res++;
                    bfs(grid, row, col, n, m);
                }
            }
        }
        return res;
    }

    void bfs(char[][] grid,int row,int col,int n,int m) {
        if (grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '2';
        bfs(grid, Math.max(0, row - 1), col, n, m);
        bfs(grid, Math.min(n - 1, row + 1), col, n, m);
        bfs(grid, row, Math.max(0, col - 1), n, m);
        bfs(grid, row, Math.min(m - 1, col + 1), n, m);
    }
}
