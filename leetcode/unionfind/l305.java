package leetcode.unionfind;

import java.util.*;

public class l305 {
    int[][] biases = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int[] uf;
    int count = 0;
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        uf = new int[m * n];
        boolean[] visited = new boolean[m * n];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < m * n; i++) {
            uf[i] = i;
        }
        for (int[] position : positions) {
            int x = position[0];
            int y = position[1];
            int index = x * n + y;
            if (!visited[index]) {
                count++;
                visited[index] = true;
                for (int[] bias : biases) {
                    int _x = x + bias[0];
                    int _y = y + bias[1];
                    int _index = _x * n + _y;
                    if(isValid(_x, _y, m, n)
                        && visited[_index]
                        && !isConnect(index,_index)
                    ) {
                        union(index, _index);
                    }
                }
            }
            res.add(count);
        }
        return res;
    }

    boolean isConnect(int i, int j) {
        return find(i) == find(j);
    }


    boolean isValid(int i, int j, int m, int n) {
        return !(i < 0 || j < 0 || i >= m || j >= n);
    }

    int find(int i) {
        if (uf[i] != i) {
            uf[i] = find(uf[i]);
        }
        return uf[i];
    }

    void union(int root, int sub) {
        int rootIndex = find(root);
        int subIndex = find(sub);
        if (rootIndex == subIndex)
            return;
        uf[subIndex] = rootIndex;
        count--;
    }
}
