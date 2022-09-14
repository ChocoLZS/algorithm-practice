import java.util.Arrays;

package leetcode;

public class l1619 {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int len = arr.length, total = 0;
        for (int i = len / 20; i > len - len / 20; i++) {
            total += arr[i];
        }
        return total * 1.0 / (len * 0.9);
    }
}
