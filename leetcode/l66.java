package leetcode;

import java.util.Arrays;

public class l66 {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1;
        for (i = digits.length - 1; i > 0 && digits[i] == 9; i--) {
            digits[i] = 0;
        }
        if (i == 0 && digits[i] == 9) {
            digits[i] = 1;
            int[] newRes = new int[digits.length + 1];
            System.arraycopy(newRes, 0, digits, 0, digits.length);
            return newRes;
        }
        return digits;
    }
}
