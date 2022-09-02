
import java.util.*;

public class l144 {

}

class Solution {
    // recursive
    // public List<Integer> preorderTraversal(TreeNode root) {
    // List<Integer> res = new LinkedList<Integer>();
    // helper(res, root);
    // return res;
    // }

    // public void helper(List<Integer> list, TreeNode node) {
    // if (node == null)
    // return;
    // list.add(node.val);
    // helper(list, node.left);
    // helper(list, node.right);
    // }

    // iterative
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            TreeNode curNode = stack.pop();
            res.add(curNode.val);
            if (curNode.right != null)
                stack.push(curNode.right);
            if (curNode.left != null) {
                stack.push(curNode.left);
            }
        }
        return res;
    }
}