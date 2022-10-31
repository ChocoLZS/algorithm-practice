package leetcode;

public class l770 {
    public int kthGrammar(int n, int k) {
        int res = 0;
        int num = (int) Math.pow(2, n - 1) + k - 1;
        while (num != 1) {
            res = res ^ num % 2;
            num = num / 2;
        }
        return res;
    }

}
