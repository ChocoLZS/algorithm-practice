package leetcode;

import java.util.*;

public class l921 {
    public int minAddToMakeValid(String s) {
        Stack<Character> stack = new Stack<>();
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            char token = s.charAt(i);
            if (token == '(') {
                stack.push(token);
            } else if (token == ')') {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    res++;
                }
            }
        }
        res += stack.size();
        return res;
    }
}
