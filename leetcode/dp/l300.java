package leetcode.dp;

public class l300 {
    // O(n^2)
    public int _lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }

    // O(nlogn)
    public int lengthOfLIS(int[] nums) {
        int piles = 0;
        int[] top = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] > poker) {
                    right = mid + 1;
                } else if (top[mid] < poker) {
                    left = mid - 1;
                } else {

                }
            }

        }
        return piles;
    }
}
