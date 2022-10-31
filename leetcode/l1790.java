package leetcode;

import java.util.ArrayList;

public class l1790 {
    public boolean areAlmostEqual(String s1, String s2) {
        ArrayList<Character> arrayList_s1 = new ArrayList<>();
        ArrayList<Character> arrayList_s2 = new ArrayList<>();
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                continue;
            } else {
                arrayList_s1.add(s1.charAt(i));
                arrayList_s2.add(s2.charAt(i));
            }
            if (arrayList_s1.size() > 2) {
                return false;
            }
        }
        if (arrayList_s1.size() == 1) {
            return false;
        }
        return arrayList_s1.size() == 0
                || (arrayList_s1.get(0).charValue() == arrayList_s2.get(1).charValue() && arrayList_s1.get(1).charValue() == arrayList_s2.get(0).charValue());
    }
}
