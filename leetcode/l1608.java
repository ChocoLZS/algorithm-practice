package leetcode;

import java.util.Arrays;

public class l1608 {
    public int specialArray(int[] nums) {
        int len = nums.length;
        Arrays.sort(nums);
        int gap = (int) Math.floor(len * 0.05);
        nums = Arrays.copyOfRange(nums, len - gap, len);
        len = nums.length;
        nums = Arrays.copyOfRange(nums, gap, len);
        len = nums.length;
        int res = 0;
        for (int item : nums) {
            res += item;
        }
        return res / len;
    }
}
