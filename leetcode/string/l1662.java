package leetcode.string;

public class l1662 {
    // public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
    //     StringBuilder sb1 = new StringBuilder();
    //     for (String word : word1) {
    //         sb1.append(word);
    //     }
    //     StringBuilder sb2 = new StringBuilder();
    //     for (String word : word2) {
    //         sb2.append(word);
    //     }
    //     return sb1.length() == sb2.length() && sb1.toString().equals(sb2.toString());
    // }
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int p1, p2, p1_ptr, p2_ptr;
        p1 = p2 = p1_ptr = p2_ptr = 0;
        while (p1 < word1.length && p2 < word2.length) {
            if (word1[p1].charAt(p1_ptr) != word2[p2].charAt(p2_ptr)) {
                return false;
            }
            p1_ptr++;
            if (p1_ptr == word1[p1].length()) {
                p1_ptr = 0;
                p1++;
            }
            p2_ptr++;
            if (p2_ptr == word1[p2].length()) {
                p2_ptr = 0;
                p2++;
            }
        }
        return p1 == word1.length && p2 == word2.length;
    }
}
