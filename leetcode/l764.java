package leetcode;

import java.util.*;

public class l764 {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int left[][] = new int[n+2][n+2];
        int top[][] = new int[n+2][n+2];
        int right[][] = new int[n+2][n+2];
        int bottom[][] = new int[n+2][n+2];
        HashSet<Integer> mineset = new HashSet<>();
        for (int[] mine : mines) {
            mineset.add(convert(mine[0]+1, mine[1]+1, n));
        }
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (!mineset.contains(convert(x, y, n))) {
                    left[x][y] = left[x - 1][y] + 1;
                    top[x][y] = top[x][y - 1] + 1;
                }
                if (!mineset.contains(convert(n - x + 1, n - y + 1, n))) {
                    right[n - x + 1][n - y + 1] = right[n - x + 2][n - y + 1] + 1;
                    bottom[n - x + 1][n - y + 1] = bottom[n - x + 1][n - y + 2] + 1;
                }
            }
        }
        int max = 0;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                max = Math.max(max, Math.min(left[x][y], Math.min(right[x][y], Math.min(top[x][y], bottom[x][y]))));
            }
        }
        return max;
    }

    int convert(int x, int y,int n) {
        return x * n + y;
    }
}
