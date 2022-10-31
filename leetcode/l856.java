import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class l856 {
    public int scoreOfParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(0);
            } else {
                int val = stack.pop();
                int top = stack.pop() + Math.max(2 * val, 1);
                stack.push(top);
            }
        }
        return stack.peek();
    }
}
