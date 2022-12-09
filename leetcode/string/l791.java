package leetcode.string;

import java.util.*;

public class l791 {
    public String customSortString(String order, String s) {
        HashSet<Character> remains = new HashSet<>();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char ch : s.toCharArray()) {
            remains.add(ch);
            if (!map.containsKey(ch)) {
                map.put(ch, 1);
            } else {
                map.put(ch, map.get(ch) + 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char ch : order.toCharArray()) {
            remains.remove(ch);
            if (map.containsKey(ch)) {
                int num = map.get(ch);
                for (int i = 0; i < num; i++) {
                    sb.append(ch);
                }
            }
        }
        for (char ch : remains) {
            int num = map.get(ch);
            for (int i = 0; i < num; i++) {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
