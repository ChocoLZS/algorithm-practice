package leetcode.unionfind;

public class l261 {
    int[] uf;

    public boolean validTree(int n, int[][] edges) {
        uf = new int[n];
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
        for (int[] edge : edges) {
            if (find(edge[0]) != find(edge[1])) {
                union(edge[0], edge[1]);
            } else {
                return false;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (uf[i] == i) {
                res++;
            }
        }
        return res == 1;
    }
    
    int find(int i) {
        if (i != uf[i]) {
            uf[i] = find(uf[i]);
        }
        return uf[i];
    }

    void union(int i, int j) {
        uf[j] = find(uf[i]);
    }
}
