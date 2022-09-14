package leetcode.dp;

// class Pair {
// int s1Idx;
// int s2Idx;

// Pair(int i, int j) {
// this.s1Idx = i;
// this.s2Idx = j;
// }

// @Override
// public int hashCode() {
// return (Integer.toString(s1Idx) + Integer.toString(s2Idx)).hashCode();
// }

// @Override
// public boolean equals(Object obj) {
// Pair pair = (Pair) obj;
// return pair.s1Idx == s1Idx && pair.s2Idx == s2Idx;
// }
// }

// public class l72 {
// private String s1;
// private String s2;
// private HashMap<Pair, Integer> memo;

// public int minDistance(String word1, String word2) {
// this.s1 = word1;
// this.s2 = word2;
// memo = new HashMap<>();

// class Inner {
// public int dp(int i, int j) {
// Pair coords = new Pair(i, j);
// if (memo.containsKey(coords))
// return memo.get(coords);
// if (i == -1)
// return j + 1;
// if (j == -1)
// return i + 1;
// if (s1.charAt(i) == s2.charAt(j)) {
// memo.put(coords, dp(i - 1, j - 1));
// } else {
// memo.put(coords, Math.min(Math.min(dp(i, j - 1) + 1, dp(i - 1, j) + 1), dp(i
// - 1, j - 1) + 1));
// }
// return memo.get(coords);
// }
// }
// return new Inner().dp(s1.length() - 1, s2.length() - 1);
// }
// }
public class l72 {

}