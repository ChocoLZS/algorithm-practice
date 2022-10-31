package leetcode;

public class l643 {
    public double findMaxAverage(int[] nums, int k) {
        double max = 0;
        long total = 0;
        for (int i = 0; i < k; i++) {
            total += nums[i];
        }
        max = (double) total / k;
        for (int i = k; i < nums.length; i++) {
            total = total - nums[i - k] + nums[i];
            max = Math.max(max, (double) total / k);
        }
        return max;
    }
}
