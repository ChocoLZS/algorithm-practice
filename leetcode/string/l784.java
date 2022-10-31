package leetcode.string;

import java.util.*;

public class l784 {
    List<Integer> indexes;
    Set<String> res;

    public List<String> letterCasePermutation(String s) {
        indexes = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if ((s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
                    || (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')) {
                indexes.add(i);
            }
        }
        if (indexes.size() == 0) {
            List<String> _res = new ArrayList<>();
            _res.add(s);
            return _res;
        }
        res = new HashSet<>();
        helper(s, 0);
        return new ArrayList<>(res);
    }

    void helper(String s, int index) {
        if (index >= indexes.size()) {
            return;
        }
        StringBuilder sb = new StringBuilder(s);
        int i = indexes.get(index);
        //lower
        sb.setCharAt(i, Character.toLowerCase(s.charAt(i)));
        res.add(sb.toString());
        helper(sb.toString(), index+1);
        //upper
        sb.setCharAt(i, Character.toUpperCase(s.charAt(i)));
        res.add(sb.toString());
        helper(sb.toString(), index+1);
    }   
}
