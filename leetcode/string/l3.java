package leetcode.string;

import java.util.HashMap;
import java.util.Map;

public class l3 {

}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int start, end;
        Map<Character, Integer> map = new HashMap<>();
        start = end = 0;
        while (end < s.length()) {
            char ch = s.charAt(end);
            if (map.containsKey(ch)) {
                int curIndex = map.get(ch).intValue();
                for (; start < curIndex; start++) {
                    map.remove(s.charAt(start));
                }
            }
            map.put(ch, end);
            ans = Math.max(ans, end - start + 1);
            end += 1;
        }
        return ans;
    }
}