public class l53 {
    public int maxSubArray(int[] nums) {
        int length = nums.length;
        int dp_last = nums[0];
        int dp_cur;
        int max = nums[0];
        for (int i = 1; i < length; i++) {
            if (nums[i] + dp_last < nums[i]) {
                dp_cur = nums[i];

            } else {
                dp_cur = nums[i] + dp_last;

            }
            max = Math.max(max, dp_cur);
            dp_last = dp_cur;
        }
        return max;
    }
}
