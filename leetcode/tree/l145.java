import java.util.*;

public class l145 {

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        Stack<TreeNode> stack2 = new Stack<TreeNode>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            TreeNode curNode = stack.top();
            stack2.push(curNode);
            if (curNode.left != null) {
                stack.push(curNode.left);
            }

            if (curNode.right != null) {
                stack.push(curNode.right);
            }
        }
        while (!stack2.isEmpty()) {
            res.add(stack2.pop().val);
        }
        return res;
    }
}