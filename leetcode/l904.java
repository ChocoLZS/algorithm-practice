package leetcode;

import java.util.HashSet;

public class l904 {
    public int totalFruit(int[] fruits) {
        int res = 0;
        int len = fruits.length;
        int[] dp = new int[len + 1];
        
        return res;
    }
    // public int totalFruit(int[] fruits) {
    //     int res = 0;
    //     int len = fruits.length;
    //     int[] counts = new int[len+1];
    //     for (int i = 0, j = 0, total = 0; i < len; i++) {
    //         counts[fruits[i]]++;
    //         if (counts[fruits[i]] == 1)
    //             total++;
    //         while (total > 2) {
    //             counts[fruits[j]]--;
    //             if(counts[fruits[j]] == 0) total--;
    //             j++;
    //         }
    //         res = Math.max(res, i - j + 1);
    //     }
        
    //     return res;
    // }
}
