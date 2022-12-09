package leetcode.dp;

public class l795 {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int n = nums.length;
        int res = 0;
        int curRes = 0;
        for (int start = 0, end = 0; end < n;) {
            int num = nums[end];
            if (num > right) {
                res += curRes;
                curRes = 0;
                end = end + 1;
                start = end;
                continue;
            }
            if (num < left) {
                if (end == 0 || nums[end - 1] > right || nums[end - 1] < left) {
                    res += curRes;
                    curRes = 0;
                    end = end + 1;
                    start = end;
                    continue;
                }
            }
            curRes = calc(end - start + 1);
            end++;
        }
        res += curRes;
        return res;
    }

    int calc(int n) {
        return (int) Math.pow(2, n) - 1;
    }
}
