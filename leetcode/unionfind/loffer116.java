package leetcode.并查集;

import java.util.HashSet;
import java.util.Set;

public class loffer116 {
    int[] fa;
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        fa = new int[n];
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    merge(j, i);
                }
            }
        }
        Set<Integer> res = new HashSet<>();
        for (int num : fa) {
            res.add(find(num));
        }
        return res.size();
    }

    int find(int i) {
        if (i == fa[i]) {
            return i;
        } else {
            return find(fa[i]);
        }
    }

    void merge(int i, int j) {
        fa[find(i)] = find(j);
    }
}
