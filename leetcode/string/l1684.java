package leetcode.string;

import java.util.*;

public class l1684 {
    public int countConsistentStrings(String allowed, String[] words) {
        int hash = 0;
        for (char c : allowed.toCharArray()) {
            hash |= (1 << (c - 'a'));
        }
        int res = 0;
        there: for (String word : words) {
            for (char c : word.toCharArray()) {
                if (((hash >> (c - 'a') & 1) == 0))
                    continue there;
            }
            res++;
        }
        return res;
    }
}
