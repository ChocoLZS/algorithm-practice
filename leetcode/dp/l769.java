package leetcode.dp;

import java.util.Stack;

public class l769 {
    public int maxChunksToSorted(int[] arr) {
        int max = 0, total = 0;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
            if(max == i){
                total = total +1;
            }
        }
        return total;
    }
}
