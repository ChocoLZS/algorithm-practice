package leetcode.string;

public class l14 {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder sb = new StringBuilder();
        int minLen = Integer.MAX_VALUE;
        for (String str : strs) {
            minLen = Math.min(minLen, str.length());
        }
        char ch;
        for (int charIndex = 0; charIndex < minLen; charIndex++) {
            ch = strs[0].charAt(charIndex);
            for (int i = 1; i < strs.length; i++) {
                if (ch != strs[i].charAt(charIndex)) {
                    ch = '#';
                    break;
                }
            }
            if (ch == '#') {
                break;
            }
            sb.append(ch);
        }
        return sb.toString();
    }
}
