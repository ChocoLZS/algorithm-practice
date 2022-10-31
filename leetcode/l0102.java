package leetcode;

import java.util.ArrayList;

public class l0102 {
    public boolean CheckPermutation(String s1, String s2) {
        char[] str = s1.toCharArray();
        ArrayList<Character> arrayList = new ArrayList<>();
        for (char ch : str) {
            arrayList.add(ch);
        }
        char[] str2 = s2.toCharArray();
        for (char ch : str2) {
            if (!arrayList.contains(ch)) {
                return false;
            }
            arrayList.remove(Character.valueOf(ch));
        }
        return arrayList.size() == 0;
    }
}
