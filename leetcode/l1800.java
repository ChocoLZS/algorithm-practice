package leetcode;

public class l1800 {
    public int maxAscendingSum(int[] nums) {
        int max = nums[0];
        int total = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] >= nums[i - 1]) {
                total += nums[i];
            } else {
                total = nums[i];
            }
            System.out.println(total);
            max = Math.max(total, max);
        }
        return max;
    }
}
