package leetcode.unionfind;

import java.util.*;

public class l128 {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        UF uf = new UF(n);
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (map.containsKey(nums[i]))
                continue;
            if (map.containsKey(nums[i] - 1)) {
                uf.merge(i,map.get(nums[i] - 1));
            }
            if (map.containsKey(nums[i] + 1)) {
                uf.merge(i,map.get(nums[i] + 1));
            }
            map.put(nums[i],i);
        }
        return uf.getMaxConnectSize();
    }
}

class UF {
    private int[] root;
    private int[] size;

    public UF(int n) {
        root = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            root[i] = i;
            size[i] = 1;
        }
    }

    public void merge(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ)
            return;
        root[rootI] = rootJ;
        size[rootJ] += size[rootI];
    }

    private int find(int i) {
        if (root[i] != i) {
            root[i] = find(root[i]);
        }
        return root[i];
    }

    public int getMaxConnectSize() {
        int max = 0;
        for (int i = 0; i < size.length; i++) {
            if (i == root[i]) {
                max = Math.max(max, size[i]);
            }
        }
        return max;
    }
}
