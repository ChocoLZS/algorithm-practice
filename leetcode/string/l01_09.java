package leetcode.string;

public class l01_09 {
    public boolean isFlipedString(String s1, String s2) {
        String res = s2 + s2;
        return s1.length() == s2.length() && res.contains(s1);
    }
}
