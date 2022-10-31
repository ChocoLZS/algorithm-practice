package leetcode;
import java.util.*;
public class l1652{
    public int[] decrypt(int[] code, int k) {
        int N = code.length;
        int[] res = new int[N];
        if (k > 0) {
            for (int i = 0; i < N; i++) {
                for (int count = 1; count <= k; count++) {
                    res[i] += code[(i + count + N) % N];
                }
            }
        } else if(k < 0){
            for (int i = 0; i < N; i++) {
                for (int count = -1; count >= -k; count--) {
                    res[i] += code[(i + count + N) % N];
                }
            }
        }
        return res;
    }
}