package leetcode.dp;

public class l775 {
    public boolean isIdealPermutation(int[] nums) {
        int n = nums.length;
        int max = nums[0];
        for (int i = 2; i < n; i++) {
            if (max > nums[i]) {
                return false;
            }
            max = Math.max(max, nums[i - 1]);
        }
        return true;
    }
}
