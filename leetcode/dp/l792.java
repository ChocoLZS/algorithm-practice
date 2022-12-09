package leetcode.dp;

import java.util.*;

public class l792 {
    public int numMatchingSubseq(String s, String[] words) {
        HashMap<Character, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!map.containsKey(ch)) {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(ch, list);
            } else {
                ArrayList<Integer> list = map.get(ch);
                list.add(i);
                map.put(ch, list);
            }
        }
        int res = words.length;
        for (String word : words) {
            if (word.length() > s.length()) {
                res--;
                continue;
            }
            int curIndex = -1;
            for (char ch : word.toCharArray()) {
                if (!map.containsKey(ch)) {
                    res--;
                    continue;
                }
                ArrayList<Integer> flags = map.get(ch);
                int nextIndex = getNextIndex(flags, curIndex);
                if (nextIndex <= curIndex) {
                    res--;
                    break;
                }
                curIndex = nextIndex;
            }
        }
        return res;
    }

    public int getNextIndex(ArrayList<Integer> flags, int target) {
        int left = 0, right = flags.size() - 1;
        while (left < right) {
            int middle = ((right - left) / 2) + left;
            if (flags.get(middle) > target) {
                //往大找，可以不急-1
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return flags.get(left);
    }
}
