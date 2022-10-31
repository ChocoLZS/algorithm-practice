package leetcode;

import java.util.TreeSet;

public class l915 {
    public int partitionDisjoint(int[] nums) {
        int len = nums.length;
        int leftMax = nums[0];
        int[] minRight = new int[len];
        minRight[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            minRight[i] = Math.min(minRight[i + 1], nums[i]);
        }
        for (int i = 0; i < len; i++) {
            leftMax = Math.max(leftMax, nums[i]);
            if (leftMax <= minRight[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
}
