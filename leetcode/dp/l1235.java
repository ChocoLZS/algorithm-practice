package leetcode.dp;

import java.util.*;

public class l1235 {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int len = startTime.length;
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            list.add(new int[] { startTime[i], endTime[i], profit[i] });
        }
        Collections.sort(list, (a, b) -> a[1] - b[1]);
        int[] dp = new int[len + 1];
        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
            int k = binarySearch(list, i - 1, list.get(i - 1)[0]);
            dp[i] = Math.max(dp[i - 1], dp[k] + list.get(i - 1)[2]);
        }
        return dp[len];
    }

    int binarySearch(List<int[]> list,int right, int target) {
        int left = 0;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(list.get(mid)[1] <= target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
}
