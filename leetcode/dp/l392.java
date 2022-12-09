package leetcode.dp;

public class l392 {
    public boolean isSubsequence(String s, String t) {
        //dp
        int s_len = s.length();
        int t_len = t.length();
        int[][] 
        int s_index = 0;
        int t_index = 0;
        while (s_index < s.length() && t_index < t.length()) {
            if (t.charAt(t_index) == s.charAt(s_index)) {
                s_index++;
            }
            t_index++;
        }
        return s_index == s.length();
    }
}
