package leetcode;

import java.util.*;

public class l1620 {
    public int[] bestCoordinate(int[][] towers, int radius) {
        ArrayList<int[]> biases = new ArrayList<>();
        for (int y = -1 * radius; y <= radius; y++) {
            if (y >= 0) {
                for (int x = y - radius; x <= radius - x; x++) {
                    biases.add(new int[] { x, y });
                }
            } else {
                for (int x = -1 * (y + radius); x <= (y + radius); x++) {
                    biases.add(new int[] { x, y });
                }
            }
        }
        int[][] graph = new int[101][101];
        int maxX = 0, maxY = 0, max = 0;
        for (int[] tower : towers) {
            int x = tower[0], y = tower[1], q = tower[2];
            for (int dx = Math.max(0, x - radius); dx <= x + radius; dx++) {
                for (int dy = Math.max(0, y - radius); dy <= y + radius; dy++) {
                    double d = Math.sqrt((dx - x) * (dx - x) + (dy - y) * (dy - y));
                    if (d > radius)
                        continue;
                    graph[dx][dy] += Math.floor(q / (1 + d));
                    if (graph[dx][dy] > max) {
                        maxX = dx;
                        maxY = dy;
                        max = graph[dx][dy];
                    } else if (graph[dx][dy] == max && (dx < maxX || (dx == maxX && dy < maxY))) {
                        maxX = dx;
                        maxY = dy;
                    }
                }
            }
        }
        return new int[] {maxX,maxY};
    }
}
