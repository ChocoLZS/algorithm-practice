package leetcode.string;

import java.util.HashSet;
import java.util.Set;

public class l3 {

}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int start, end;
        Set<Character> set = new HashSet<>();
        start = end = 0;
        while (end < s.length()) {
            char ch = s.charAt(end);
            if(set.contains())
        }
        return ans;
    }
}