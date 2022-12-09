package leetcode.string;
public class l1704 {
    public boolean halvesAreAlike(String s) {
        int pron = 0b100000100000100010001;
        s = s.toLowerCase();
        String leftpart = s.substring(0, s.length() / 2);
        String rightpart = s.substring(s.length() / 2, s.length());
        int res = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            char left = leftpart.charAt(i);
            char right = rightpart.charAt(i);
            if (((pron >> (left - 'a')) & 1)  == 1) {
                res--;
            }
            if (((pron >> (right - 'a')) & 1) == 1) {
                res++;
            }
        }
        return res == 0;
    }
}
