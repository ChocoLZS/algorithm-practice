package leetcode.unionfind;

public class l200 {
    int[] uf;
    int count = 0;
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        uf = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            uf[i] = i;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    
                }
            }
        }
    }

    boolean isConnect(int i, int j) {
        return find(i) == find(j);
    }

    int find(int i) {
        if (uf[i] != i) {
            uf[i] = find(i);
        }
        return uf[i];
    }

    void union(int root, int sub) {
        int rootIndex = find(root);
        int subIndex = find(sub);
        if (rootIndex == subIndex) {
            return;
        }
        uf[subIndex] = rootIndex;
        count--;
    }

}
